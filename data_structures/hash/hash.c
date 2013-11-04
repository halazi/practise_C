#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct node {
	int key;
	int val;
	struct node *next;
} list_t;

int hash(int key)
{
	return key % N;
}

void init(list_t* ht[])
{
	int i;
	for (i=0; i<N; i++) {
		ht[i] = NULL;
	}
}

void insert(list_t *ht[], int key)
{
	printf("insert %d: ", key);
	int h = hash(key);
	if (ht[h] == NULL) {
		printf("no collision\n");
		list_t *tmp = malloc(sizeof(list_t));
		tmp->key = key;
		tmp->val = 1;
		tmp->next = NULL;
		ht[h] = tmp;
	} else {
		printf("collision, ");
		list_t *curr = ht[h];
		while (curr != NULL) {
			if (curr->key == key) {
				curr->val++;
				printf("not new node, val++, val=%d\n", curr->val);
				return;
			}
			curr = curr->next;
		}
		printf("new node\n");
		list_t *tmp = malloc(sizeof(tmp));
		tmp->key = key;
		tmp->val = 1;
		tmp->next = ht[h];
		ht[h] = tmp;
	}
}

void delete(list_t *ht[], int key)
{
	printf("delete %d, ", key);
	int h = hash(key);
	list_t *curr = ht[h];
	list_t *prev = NULL;
	while (curr != NULL) {
		if (curr->key == key) {
			printf("deleted, val=%d\n", curr->val);
			if (prev == NULL) {
				ht[h] = curr->next;
				free(curr);
				return;
			} else {
				prev->next = curr->next;
				free(curr);
				return;
			}
		}
		prev = curr;
		curr = curr->next;
	}
	printf("key not found\n");
}

int main()
{
	list_t *hash_table[N];
	init(hash_table);
	insert(hash_table, 6);
	insert(hash_table, 7);
	insert(hash_table, 6);
	insert(hash_table, 9);
	insert(hash_table, 1);
	insert(hash_table, 8);
	insert(hash_table, 16);
	delete(hash_table, 1);
	delete(hash_table, 2);
	delete(hash_table, 6);
	delete(hash_table, 8);
	delete(hash_table, 9);
	delete(hash_table, 10);
	return 0;
}
