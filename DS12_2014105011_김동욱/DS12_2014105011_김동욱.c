#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(size) (size==MAX_ELEMENTS-1)
#define HEAP_EMPTY(size) (!size)

typedef struct Run {
	int key[100];
	int ptr;
	int size;
}Run;

int *heap;
Run *run;
void check_k(int k) {
	int check, i;
	for (i = 1; i < k; i = i * 2) {

	}
	if (k == i || k == i - 1) {
		return;
	}
	else {
		printf("winner tree는 completebinary tree가 되어야합니다. 다시입력해주세요");
		exit(1);
	}
}
int file_input() {
	FILE *f;
	int k;
	
	int i, input,j;

	f = fopen("input.txt", "r");

	fscanf(f, "%d", &k);
	check_k(k);
	run = (Run*)malloc(sizeof(Run)*k);
	
	i = 0;
	while (!feof(f)) {
		j = 0;
		while (1) {
			fscanf(f, "%d", &input);
			if (input == -1)
				break;
			run[i].key[j] = input;
			j++;
		}
		run[i].size = j;
		run[i].ptr = 0;
		i++;
		if (i >= k)
			break;
	}
	return k;
}
//treePointer maketree(int size) {
//	treePointer *leafnode,temp,nextNodeA,nextNodeB;
//	int i,j,round=1;
//	leafnode = (node**)malloc(sizeof(node*)*size);
//	for (i = 0; i < size; i++) {
//		leafnode[i] = (node*)malloc(sizeof(node));
//		leafnode[i] = run[j].key[run[j].ptr];
//		leafnode[i]->parent = NULL;
//		leafnode[i]->leftChild = NULL;
//		leafnode[i]->rightChild = NULL;
//	}
//	
//	for (i = size; i> 1; i / 2) {
//		for (j = 0; j < i; j = j + 2) {
//				/*leafnode[j]->parent= (node*)malloc(sizeof(node));
//				if (leafnode[j]->data > leafnode[j + 1]->data)
//				{
//					leafnode[j]->parent->data = leafnode[j + 1]->data;
//				}
//				else {
//					leafnode[j]->parent->data = leafnode[j]->data;
//				}
//				leafnode[j]->parent->leftChild = leafnode[j];
//				leafnode[j]->parent->rightChild = leafnode[j + 1];
//				leafnode[j]->parent = NULL;
//				round = round * 2;*/
//			nextNodeA = findParent(leafnode[j]);
//			nextNodeB = findParent(leafnode[j + round]);
//			nextNodeA->parent = (node*)malloc(sizeof(node));
//			if (nextNodeA->data > nextNodeB->data)
//			{
//				nextNodeA->parent->data = nextNodeB->data;
//			}
//			else {
//				nextNodeA->parent->data = nextNodeA->data;
//			}
//			nextNodeA->parent->leftChild = nextNodeA;
//			nextNodeB->parent->rightChild = nextNodeB;
//			nextNodeA->parent = NULL;
//			nextNodeB->parent = nextNodeA->parent;
//			round = round * 2;
//		}
//	}
//	return nextNodeA->parent;
//}

int find_leftleaf(int size) {
	int i;
	for (i = 1; i<size; i = i * 2) {
	}

	return i;
}
int make_wintree(int size,int heapsize){
	int i, j, round = 1,left;
	int cnt=0,index=size-1;
	for (i = heapsize;index>=0; i--) {
		heap[i] = run[index].key[run[index].ptr];
		index--;

	}
	left = find_leftleaf(size);
	i = left;
	for (; i > 1;) {
		if (i == heapsize) {
			heap[i / 2] = heap[i];
		}
		else {
			if (heap[i] > heap[i + 1])
				heap[i / 2] = heap[i + 1];
			else {
				heap[i / 2] = heap[i];
			}
		}
		i = i + 2;
		if(i>=left*2) {
			left = left / 2;
			i = left;
		}
	}
	/*for (i = heapsize; i > 1;) {
		if (heap[i] > heap[i - 1])
			heap[i / 2] = heap[i - 1];
		else {
			heap[i / 2] = heap[i];
		}
		i = i - 2;
	}*/
	
	for (i = 0; i < size; i++)//위너제거
	{
		if (heap[1] == run[i].key[run[i].ptr])
		{
			run[i].ptr++;
			break;
		}
	}
	return heap[1];
}

int find_heapsize(int size) {
	int i,heapsize=0;
	for (i = 1;; i = i * 2) {
		if(i<size)
			heapsize += i;
		else
		{
			heapsize += size;
			break;
		}
	}
	heap = (int*)malloc(sizeof(int)*heapsize+1);

	return heapsize;
}
void levelorder(int heapsize) {
	int i;
	for (i = 1; i <= heapsize; i++) {
		printf("%d ", heap[i]);
	}
}
void inorder(int i,int heapsize) {
	if (i <= heapsize) {
		inorder(i * 2,heapsize);
		printf("%d ", heap[i]);
		inorder(i * 2 + 1,heapsize);
	}
}
int main() {
	int size,heapsize;
	int i;
	size = file_input();
	heapsize = find_heapsize(size);
	
	printf("Winner : %d", make_wintree(size, heapsize));
	printf("\nLevel order : ");
	levelorder(heapsize);
	printf("\nInorder : ");
	inorder(1,heapsize);
	printf("\nWinner : %d", make_wintree(size, heapsize));
	printf("\nLevel order : ");
	levelorder(heapsize);
	printf("\nInorder : ");
	inorder(1,heapsize);
	printf("\n");
}