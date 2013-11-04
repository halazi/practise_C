#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int v;
	struct node *next;
} list_t;

void add(list_t **h, int v) {
	printf("add %d\n", v);
	list_t *node = malloc(sizeof(list_t));
	node->v = v;
	node->next = *h;
	*h = node;
}

void del(list_t **h, int v) {
	printf("del %d\n", v);
	list_t *curr = *h;
	list_t *prev = NULL;
	while (curr != NULL) {
		if (curr->v == v) {
			if (prev == NULL) {
				*h = curr->next;
			} else {
				prev->next = curr->next;
			}
			free(curr);
			printf("find value\n");
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	printf("no value\n");
}

void print_list(list_t *h) {
	printf("list: ");
	while (h != NULL) {
		printf("%d ", h->v);
		h = h->next;
	}
	printf("\n");
}

int main() {
	list_t *head = NULL;
	add(&head, 1);
	print_list(head);
	add(&head, 2);
	print_list(head);
	add(&head, 3);
	print_list(head);
	add(&head, 4);
	print_list(head);
	del(&head, 1);
	print_list(head);
	del(&head, 2);
	print_list(head);
	del(&head, 4);
	print_list(head);
	add(&head, 5);
	print_list(head);
	del(&head, 4);
	print_list(head);
	del(&head, 3);
	print_list(head);
	return 0;
}
