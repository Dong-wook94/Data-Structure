#include <stdio.h>
typedef struct Key {
	int k1;
	int k2;
}Key;

Key *key;
int record_num;
void file_input();
void insert(Key k, int i,int key_arr);
void insertion_sort(int key_arr);
void SWAP(Key a, Key b);
void quick_sort(int left, int right,int key_arr);
void print_key();
int main() {
	file_input();
	//print_key();
	printf("Insertion Sort\n");
	insertion_sort(1);
	printf("Key: K1\n");
	print_key();
	insertion_sort(2);
	printf("Key: K2\n");
	print_key();
	printf("\nQucik Sort\n");
	printf("Key: K1\n");
	quick_sort(1, record_num,1);
	print_key();
	printf("Key: K2\n");
	quick_sort(1, record_num, 2);
	print_key();
}
void file_input() {
	FILE *f;
	int i;
	f = fopen("input.txt", "r");

	fscanf(f, "%d", &record_num);
	key = (Key*)malloc(sizeof(Key)*record_num+1);
	for (i = 1; i <= record_num; i++) {
		fscanf(f, "%d %d", &key[i].k1, &key[i].k2);
	}

}
void insert(Key k, int i,int key_arr) {
	key[0] = k;
	if (key_arr == 1) {
		
		while (k.k1<key[i].k1)
		{
			key[i + 1] = key[i];
			i--;
		}
	}
	else {
		
		while (k.k2<key[i].k2)
		{
			key[i + 1] = key[i];
			i--;
		}
	}
	key[i + 1] = k;
}
void insertion_sort(int key_arr) {
	int j;
	for (j = 2; j <= record_num; j++) {
		Key temp = key[j];
		insert(temp, j - 1,key_arr);
	}
}
void SWAP(Key a, Key b) {
	Key temp;

	temp = a;
	a = b;
	b = temp;
}
void quick_sort(int left, int right, int key_arr) {
	int pivot, i, j;
	Key temp;
	if (left < right) {
		i = left;
		j = right + 1;
		if (key_arr == 1) {
			pivot = key[left].k1;
			do {
				do i++; while (key[i].k1 < pivot);
				do j--; while (key[i].k1 < pivot);
				if (i < j) SWAP(key[i], key[j]);
			} while (i < j);
			SWAP(key[left], key[j]);
		}
		else {
			pivot = key[left].k2;
			do {
				do i++; while (key[i].k2 < pivot);
				do j--; while (key[i].k2 < pivot);
				if (i < j) SWAP(key[i], key[j]);
			} while (i < j);
			SWAP(key[left], key[j]);
		}
		
		quick_sort(left, j-1, key_arr);
		quick_sort(j + 1, right, key_arr);
	}
}
void print_key() {
	int i;
	
	for (i = 1; i <= record_num; i++) {
		printf("%d %d\n", key[i].k1, key[i].k2);
	}
}