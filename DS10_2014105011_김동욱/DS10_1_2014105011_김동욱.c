#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(size) (size==MAX_ELEMENTS-1)
#define HEAP_EMPTY(size) (!size)
typedef struct element {
	int key;
}element;
element heap[MAX_ELEMENTS];
typedef struct Stack {
	int *key;
	int ptr;
}Stack;
Stack stack;
//void file_input();
int size = 0;
int j;
void stack_push(int num) {
	stack.key[++stack.ptr] = num;
}
int stack_pop() {
	return stack.key[stack.ptr--];
}
int move_left(int num) {
	while (num < size) {//
		num = num * 2;
	}
	num = num / 2;
	return num;
}
int search_endpoint() {
	int i = 1;
	while (i <= size) {
		i = i * 2;
	}
	i = i / 2;
	return i;
}
void inorder() {
	int i;
	int check = 0;
	stack.ptr = -1;
	stack.key = (int*)malloc(sizeof(int)*size);
	//if (i <= size)
	i = 1;
	for (;;) {
		for (; i <= size; i = i * 2) {
			stack_push(i);
			check = 1;
		}
		if (check == 1) {
			i = stack_pop();
			printf("%d ", heap[i].key);
		}
	
		if (stack.ptr <= -1)
			break;
		i = stack_pop();
		printf("%d ", heap[i].key);
		i = i*2 + 1;
		check = 0;
	}
}
void levelorder(int i) {
	int n;
	for (n = i; n <= size; n++)
		printf("%d ", heap[n].key);
}
void heap_push(element item) {
	int i;
	if (HEAP_FULL(size)) {
		printf("heap²ËÂü ¿À·ù\n");
		exit(1);
	}
	i = ++size;
	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}

void heap_delete() {
	element temp;
	int parent, child;
	if (HEAP_EMPTY(size)) {
		printf("heap empty\n");
		exit(1);
	}
	temp = heap[size--];
	parent = 1;
	child = 2;
	while (child <= size) {
		if ((child < size) && heap[child].key < heap[child + 1].key)
			child++;
		if (temp.key >= heap[child].key)break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;

}


int main() {
	FILE *f;
	int cnt = 0;
	element item;
	printf("!!!");
	f = fopen("input1.txt", "r");

	while (!feof(f)) {
		fscanf(f, "%d ", &item.key);
		heap_push(item);
	}
	printf("Level Order: ");
	levelorder(1);
	printf("\nInorder: ");
	inorder();
	heap_delete();
	printf("\nLevel Order: ");
	levelorder(1);
	printf("\nInorder: ");
	inorder();
	heap_delete();
	printf("\nLevel Order: ");
	levelorder(1);
	printf("\nInorder: ");
	inorder();
	return 0;
}

