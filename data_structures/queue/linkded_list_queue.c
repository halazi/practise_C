#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *next;
} list_t;

typedef struct {
	list_t *head;
	list_t *tail;
} queue_t;

void init(queue_t *p)
{
	p->head = NULL;
	p->tail = NULL;
}

void enq(queue_t *p, int v)
{
	printf("enq %d\n", v);
	list_t *tmp = malloc(sizeof(list_t));
	tmp->val = v;
	tmp->next = NULL;
	if (p->head == NULL) {
		p->head = tmp;
		p->tail = tmp;
	} else {
		p->tail->next = tmp;
		p->tail = tmp;
	}
}

void deq(queue_t *p)
{
	if (p->head == NULL) {
		printf("empty\n");
		return;
	} else {
		list_t *tmp = p->head;
		p->head = p->head->next;
		if (p->head == NULL) {
			p->tail = NULL;
		}
		int v = tmp->val;
		free(tmp);
		printf("deq %d\n", v);
	}
}

int main()
{
	queue_t q;
	init(&q);
	enq(&q, 1);
	deq(&q);
	enq(&q, 3);
	enq(&q, 2);
	deq(&q);
	deq(&q);
	deq(&q);
	deq(&q);
	enq(&q, 2);
}
