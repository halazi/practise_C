// BST containing integers

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} BST;

void insert(BST **ptr, int i)
{
	if (*ptr == NULL) {
		BST *tmp = (BST *)malloc(sizeof(BST));
		tmp->data = i;
		tmp->left = NULL;
		tmp->right = NULL;
		*ptr = tmp;
	} else {
		if (i <= (*ptr)->data) {
			insert(&(*ptr)->left, i);
		} else {
			insert(&(*ptr)->right, i);
		}
	}
}

void print_tree(BST *tr)
{
	if (tr == NULL) {
		return;
	} else {
		if (tr->left != NULL) {
			print_tree(tr->left);
		}
		printf("%d ", tr->data);
		if (tr->right != NULL) {
			print_tree(tr->right);
		}
	}
}

void print_expr(BST *tr)
{
	if (tr == NULL) {
		printf("NULL");
	} else {
		printf("%d\t", tr->data);
		print_expr(tr->left);
		printf("\v");
		print_expr(tr->right);
	}
}

int main()
{
	printf("Type in numbers:");
	BST *tree = NULL;
	BST **ptr = &tree;
	int ti;
	while (scanf("%d", &ti) != EOF) {
		insert(ptr, ti);
	}
	print_tree(tree);
	print_expr(tree);
	printf("\nnumber to delete: ");
	int n;
	scanf("%d", &n);
	//delete(tree, n);
	print_tree(tree);
	return 0;
}
