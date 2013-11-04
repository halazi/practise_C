#include <stdio.h>
#define EXPR_SIZE 32
#define STACK_SIZE 32

typedef struct {
	int top;
	char s[STACK_SIZE];
} Stack;

void init(Stack *p)
{
	p->top = 0;
}

int is_empty(Stack *p)
{
	if (p->top == 0) {
		return 1;
	} else {
		return 0;
	}
}

void push(Stack *p, char c)
{
	p->s[p->top] = c;
	p->top++;
}

int pop(Stack *p)
{
	if (is_empty(p)) {
		return -1;
	} else {
		p->top--;
		return p->s[p->top];
	}
}

int top(Stack *p)
{
	if (is_empty(p)) {
		return -1;
	} else {
		return p->s[p->top-1];
	}
}

int main()
{
	char expr[EXPR_SIZE];
	printf("Type in the mathematical expression:\n");
	scanf("%s", expr);

	Stack rand, rator;
	Stack *prand = &rand;
	Stack *prator = &rator;
	init(prand);
	init(prator);
	char *p = expr;
	while (*p != '\0') {
		if (*p >= '0' && *p <= '9') {
			push(prand, *p);
		} else {
			if (*p == '+' || *p == '-') {
				int c = top(prator);
				if (c == -1) {
					push(prator, *p);
				} else {
					char ator = (char)pop(prator);
					char and_2 = (char)pop(prand);
					char and_1 = (char)pop(prand);
					char new_and;
					switch (ator) {
						case '+':
							new_and = (char)((and_1 - '0') + (and_2 - '0'));
					}
				}
			}
		}
	}

	return 0;
}
