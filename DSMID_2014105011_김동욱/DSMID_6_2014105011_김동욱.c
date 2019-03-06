#include <stdio.h>
#include <stdlib.h>
typedef struct listNode *listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;

void print_node(listPointer first) {
	listPointer nextNode, temp;
	for (nextNode = first; nextNode; nextNode = nextNode->link) {
		printf("%d ", nextNode->data);
	}
}

listPointer insert_node(listPointer first, int num) {
	listPointer nextNode, temp;

	temp = (listNode*)malloc(sizeof(listNode));
	temp->data = num;
	temp->link = NULL;
	if (first->data > temp->data) {
		temp->link = first;
		return temp;
	}
	for (nextNode = first; nextNode->link; nextNode = nextNode->link) {
		if (nextNode->link->data > temp->data) {
			temp->link = nextNode->link;
			nextNode->link = temp;
			return first;
		}
	}
	nextNode->link = temp;
	return first;
}
int main() {
	FILE *f;
	int input;
	listPointer first;
	f = fopen("input.txt", "r");
	//printf("!!");
	first = (listNode*)malloc(sizeof(listNode));
	first->data = NULL;
	first->link = NULL;

	while (!feof(f)) {
		fscanf(f, "%d", &input);
		//printf("input : %d\n",input);
		if (first->data) {
			first = insert_node(first, input);
		}
		else {
			first->data = input;
			first->link = NULL;
		}
	}
	fclose(f);
	print_node(first);
	return 0;
}