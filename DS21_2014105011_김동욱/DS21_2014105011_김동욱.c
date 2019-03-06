#include <stdio.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(size) (size==MAX_ELEMENTS-1)
#define HEAP_EMPTY(size) (!size)
typedef struct Key {
	int k1;
	int k2;
}Key;
Key *key;
Key *heap;
int record_num;

int size = 0;
void file_input();
void heap_push(Key item);
void make_max_heap(int keyarr);
void adjust(int root);
void SWAP(Key a, Key b);
void heapSort(int keyarr);
void print_heap(int keyarr);
void print_key();

int main() {
	file_input();
	int left, i;

	printf("Key: K1\n");
	printf("Initial Heap\n");
	make_max_heap(1);
	print_key();

	printf("Heap Sort\n");
	heapSort(1);
	//print_key();
	print_heap(1);

	printf("Key: K2\n");
	printf("Initial Heap\n");
	make_max_heap(2);
	print_key();

	printf("Heap Sort\n");
	heapSort(2);
	//print_key();
	print_heap(2);

	
}

void file_input() {
	FILE *f;
	int i;
	f = fopen("input.txt", "r");

	fscanf(f, "%d", &record_num);
	key = (Key*)malloc(sizeof(Key)*record_num + 1);
	heap = (Key*)malloc(sizeof(Key)*record_num + 1);
	for (i = 1; i <= record_num; i++) {
		fscanf(f, "%d %d", &key[i].k1, &key[i].k2);
	}

}
void heap_push(Key item,int keyarr) {
	int i;
	if (HEAP_FULL(size)) {
		printf("heap²ËÂü ¿À·ù\n");
		exit(1);
	}
	i = ++size;
	if (keyarr == 1) {
		while ((i != 1) && (item.k1 > heap[i / 2].k1)) {
			heap[i] = heap[i / 2];
			i /= 2;
		}
		heap[i] = item;
	}
	else {
		while ((i != 1) && (item.k2 > heap[i / 2].k2)) {
			heap[i] = heap[i / 2];
			i /= 2;
		}
		heap[i] = item;
	}
	
}
void make_max_heap(int keyarr) {
	int i;
	for (i = 1; i <= record_num; i++) {
		heap_push(key[i],keyarr);
	}
}
void adjust(int root, int keyarr) {
	int child, rootkey;
	Key temp;
	if (keyarr == 1) {
		temp = heap[root];
		rootkey = heap[root].k1;
		child = 2 * root;
		while (child <= record_num) {
			if ((child < record_num) && (heap[child].k1 > heap[child + 1].k1))
				child++;
			if (rootkey < heap[child].k1)
				break;
			else {
				heap[child / 2] = heap[child];
				child *= 2;
			}
			heap[child / 2] = temp;
		}
	}
	else {
		temp = heap[root];
		rootkey = heap[root].k2;
		child = 2 * root;
		while (child <= record_num) {
			if ((child < record_num) && (heap[child].k2 > heap[child + 1].k2))
				child++;
			if (rootkey < heap[child].k2)
				break;
			else {
				heap[child / 2] = heap[child];
				child *= 2;
			}
			heap[child / 2] = temp;
		}
	}
	
	
}
void SWAP(Key a, Key b) {
	Key temp;

	temp = a;
	a = b;
	b = temp;
}
void heapSort(int keyarr) {
	int i, j;	
	Key temp;

	for (i = record_num / 2; i > 0; i--) {
		adjust(i,keyarr);
	}
	for (i = record_num - 1; i > 0; i--) {
		SWAP(heap[1], heap[i + 1]);
		adjust(1,keyarr);
	}

}
Key heap_delete(int keyarr) {
	Key temp;
	Key value;
	int parent, child;
	if (HEAP_EMPTY(size)) {
		printf("heap empty\n");
		exit(1);
	}
	value = heap[1];
	temp = heap[size--];
	parent = 1;
	child = 2;
	if (keyarr == 1) {
		while (child <= size) {
			if ((child < size) && heap[child].k1 > heap[child + 1].k1)
				child++;
			if (temp.k1 <= heap[child].k1)break;
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
	}
	else {
		while (child <= size) {
			if ((child < size) && heap[child].k2 > heap[child + 1].k2)
				child++;
			if (temp.k2 <= heap[child].k2)break;
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
	}
	
	heap[parent] = temp;
	return value;
}

void print_heap(int keyarr) {
	int i;
	Key value;
	for (i = 1; i <= record_num; i++) {
		value = heap_delete(keyarr);
		printf("%d %d\n", value.k1, value.k2);
	}
}
void print_key() {
	int i;

	for (i = 1; i <= record_num; i++) {
		printf("%d %d\n", heap[i].k1, heap[i].k2);
	}
}
