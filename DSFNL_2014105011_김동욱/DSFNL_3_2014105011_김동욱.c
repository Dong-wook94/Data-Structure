#include <stdio.h>
typedef struct BST *treePointer;
typedef struct BST {
	int data;
	treePointer leftChild;
	treePointer rightChild;
	int level;
}BST;

treePointer root;
int maxlevel;
void file_input();
void input_tree(int input);
void preorder(treePointer node);
void inorder(treePointer node);
void postorder(treePointer node);
int main() {
	file_input();
	printf("Preorder : ");
	preorder(root);
	printf("\nInorder : ");
	inorder(root);
	printf("\nPostorder : ");
	postorder(root);
	printf("\nHeight : %d\n", maxlevel + 1);
}

void file_input() {
	FILE *f;
	int input;

	f = fopen("input.txt", "r");
	root = (BST*)malloc(sizeof(BST));
	fscanf(f, "%d ", &input);
	root->data = input;
	root->leftChild = NULL;
	root->rightChild = NULL;
	root->level = 0;
	maxlevel = 0;
	while (!feof(f)) {
		fscanf(f, "%d ", &input);
		input_tree(input);
	}
}
void input_tree(int input) {
	treePointer temp;
	treePointer parent;
	int cnt = 1;
	temp = (BST*)malloc(sizeof(BST));
	temp->data = input;
	temp->leftChild = NULL;
	temp->rightChild = NULL;
	parent = root;
	while (1) {
		if (parent->data < input) {
			if (!parent->rightChild) {
				temp->level = cnt;
				parent->rightChild = temp;
				return;
			}
			else {
				parent = parent->rightChild;
				cnt++;
			}
		}
		else {
			if (!parent->leftChild) {
				temp->level = cnt;
				parent->leftChild = temp;
				return;
			}
			else {
				parent = parent->leftChild;
				cnt++;
			}
		}
	}
}
void preorder(treePointer node) {
	if (node) {
		printf("%d ", node->data);
		if (maxlevel < node->level)
			maxlevel = node->level;
		preorder(node->leftChild);
		preorder(node->rightChild);
	}
}
void inorder(treePointer node) {
	if (node) {
		inorder(node->leftChild);
		printf("%d ", node->data);
		inorder(node->rightChild);
	}
}
void postorder(treePointer node) {
	if (node) {
		postorder(node->leftChild);
		postorder(node->rightChild);
		printf("%d ", node->data);
	}
}