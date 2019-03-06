#include <stdio.h>
typedef struct listNode*listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;

listPointer file_input1();
listPointer file_input2();
void print_list(listPointer head);
listPointer list_invert(listPointer first);
listPointer list_concatenate(listPointer first, listPointer second);
int main() {
	listPointer first;
	listPointer second;
	first = file_input1();
	second = file_input2();
	printf("First:\n");
	print_list(first);
	printf("\nSecond:\n");
	print_list(second);
	printf("\nConcatenate:\n");
	first = list_concatenate(first, second);
	print_list(first);
	printf("\nInvert:\n");
	first = list_invert(first);
	print_list(first);
}
listPointer file_input1() {
	listPointer first,nextNode,temp;
	FILE *f1;
	int input;
	f1 = fopen("input1.txt", "r");

	first = (listPointer*)malloc(sizeof(listPointer));
	first->data = NULL;
	nextNode = first;
	nextNode->link = NULL;
	while (!feof(f1))
	{
		
		fscanf(f1, "%d ", &input);
		temp = (listPointer*)malloc(sizeof(listPointer));
		temp->data = input;
		temp->link = NULL;
		nextNode->link = temp;
		nextNode = nextNode->link;
	}

	fclose(f1);
	return first;
}
listPointer file_input2() {
	listPointer second, nextNode, temp;
	FILE *f2;
	int input;
	f2 = fopen("input2.txt", "r");

	second = (listPointer*)malloc(sizeof(listPointer));
	second->data = NULL;
	nextNode = second;
	nextNode->link = NULL;
	while (!feof(f2))
	{

		fscanf(f2, "%d ", &input);
		temp = (listPointer*)malloc(sizeof(listPointer));
		temp->data = input;
		temp->link = NULL;
		nextNode->link = temp;
		nextNode = nextNode->link;
	}

	fclose(f2);
	return second;
}
void print_list(listPointer head) {
	listPointer nextNode;
	nextNode = head->link;
	while (nextNode != NULL) {
		if(nextNode->link==NULL)
			printf("(%p, %d, 0) ", nextNode, nextNode->data);
		else
			printf("(%p, %d, %p) ", nextNode,nextNode->data,nextNode->link);
		nextNode = nextNode->link;
	}
}
listPointer list_concatenate(listPointer first, listPointer second) {
	listPointer temp;

	if (!first) return second;
	if (!second) return first;

	for (temp = first; temp->link!=NULL; temp = temp->link);

	temp->link = second->link;

	return first;

}
listPointer list_invert(listPointer head) {
	listPointer middle, tail;

	middle = head;
	head = head->link;
	middle->link = NULL;
	middle = NULL;
	while (head) {
		tail = middle;
		middle = head;
		head = head->link;
		middle->link = tail;
	}
	head = (listPointer*)malloc(sizeof(listPointer));
	head->link = middle;
	return head;
}