#include <stdio.h>
#include <stdlib.h>
typedef struct node *treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
}node;



void insert_node(treePointer root, int input) {
	treePointer nextNode, temp;

	temp = (node*)malloc(sizeof(node));
	temp->data = input;
	temp->leftChild = NULL;
	temp->rightChild = NULL;
	for (nextNode = root; ;) {
		if (nextNode->data > temp->data) {
			if (nextNode->leftChild) {
				nextNode = nextNode->leftChild;
				
			}
			else {
				nextNode->leftChild = temp;
				return;
			}
			
		}
		else if (nextNode->data < temp->data) {
			if (nextNode->rightChild) {
				nextNode = nextNode->rightChild;
			}
			else{
				nextNode->rightChild = temp;
				return;
			}
			
		}
		else
		{
			printf("같은값은 들어가면안됩니다.");
			exit(1);
		}

	}
	

}
treePointer file_input() {
	FILE *f;
	int input;
	treePointer root;
	f = fopen("input1.txt", "r");
	root = (node*)malloc(sizeof(node));
	if (!feof(f)) {
		fscanf(f, "%d", &input);
		root->data = input;
		root->leftChild = NULL;
		root->rightChild = NULL;
	}
	while (!feof(f)) {
		fscanf(f, "%d", &input);
		insert_node(root, input);
	}
	fclose(f);
	return root;
}

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		printf("%d ", ptr->data);
		inorder(ptr->rightChild);
	}
}
void preorder(treePointer ptr) {
	if (ptr) {
		printf("%d ", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}
void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%d ", ptr->data);
	}
}
void b_search(treePointer root, int input) {
	treePointer nextNode;
	for (nextNode = root; nextNode;) {
		if (nextNode->data > input)
			nextNode = nextNode->leftChild;
		else if (nextNode->data < input)
			nextNode = nextNode->rightChild;
		else
		{
			printf("1 ");
			return;
		}
	}
	printf("0 ");
}
void search_input(treePointer root) {
	FILE *f2;
	int input;
	treePointer nextNode;
	f2 = fopen("input2.txt", "r");

	while (!feof(f2)) {
		fscanf(f2, "%d", &input);
		b_search(root, input);
	}
}



int main() {

	treePointer root;
	root = file_input();
	
	printf("Preorder : ");
	preorder(root);
	printf("\nInorder : ");
	inorder(root);
	printf("\nPostorder : ");
	postorder(root);
	printf("\nSearch : ");
	search_input(root);
}