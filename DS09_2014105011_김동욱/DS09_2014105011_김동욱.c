#include <stdio.h>
#include <stdlib.h>
typedef struct node* treePointer;
typedef struct node {
	char data;
	treePointer leftChild, rightChild;
}node;

treePointer createNode(char data) {
	treePointer temp;

	temp = (node*)malloc(sizeof(node));

	temp->leftChild = NULL;
	temp->rightChild = NULL;
	temp->data = data;
	return temp;
}
void preorder(treePointer ptr) {
	if (ptr)
	{
		printf("%c", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}
void inorder(treePointer ptr) {
	if (ptr)
	{
		inorder(ptr->leftChild);
		printf("%c", ptr->data);
		inorder(ptr->rightChild);
	}
}
void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%c", ptr->data);
	}
}


treePointer Input_data() {
	treePointer ptr, temp;
	ptr = createNode('A');
	ptr->leftChild = createNode('B');
	ptr->rightChild = createNode('C');
	ptr->leftChild->leftChild = createNode('D');
	ptr->leftChild->leftChild->leftChild = createNode('H');
	ptr->leftChild->leftChild->rightChild = createNode('I');
	ptr->leftChild->rightChild = createNode('E');
	ptr->rightChild->leftChild = createNode('F');
	ptr->rightChild->rightChild = createNode('G');

	return ptr;
}
treePointer Input_data2() {
	treePointer ptr, temp;
	ptr = createNode('+');
	ptr->leftChild = createNode('*');
	ptr->rightChild = createNode('E');
	ptr->leftChild->leftChild = createNode('*');
	ptr->leftChild->leftChild->leftChild = createNode('/');
	ptr->leftChild->leftChild->leftChild->leftChild = createNode('A');
	ptr->leftChild->leftChild->leftChild->rightChild = createNode('B');
	ptr->leftChild->leftChild->rightChild = createNode('C');
	ptr->leftChild->rightChild = createNode('D');
	return ptr;
}

int main(){
	treePointer ptr,ptr2;
	ptr = Input_data();
	printf("Preorder: ");
	preorder(ptr);
	printf("\nInorder: ");
	inorder(ptr);
	printf("\nPostorder: ");
	postorder(ptr);
	ptr2 = Input_data2();
	printf("\nPreorder: ");
	preorder(ptr2);
	printf("\nInorder: ");
	inorder(ptr2); 
	printf("\nPostorder: ");
	postorder(ptr2);
}

