#include <stdio.h>
#include <stdlib.h>
typedef struct Key {
	int *field;
}Key;

Key *key;
void file_input();
int record_num;
int field_num;
int insertion_sort(int f);
void radix_sort();
void print_key();
int main() {
	file_input();
	radix_sort();
	print_key();
}

void file_input() {
	FILE *f;
	int i,j;

	f = fopen("input.txt", "r");

	fscanf(f, "%d %d", &record_num, &field_num);
	key = (Key*)malloc(sizeof(Key)*record_num);
	for (i = 0; i < record_num; i++) {
		key[i].field = (int*)malloc(sizeof(int)*field_num);
		for (j = 0; j < field_num; j++) {
			fscanf(f, "%d", &key[i].field[j]);
		}
	}

}
void radix_sort() {
	int i,j,k;
	Key temp;
	for (j = field_num - 1; j >= 0; j--) {
		insertion_sort(j);
		//printf("\nfiled %d:\n", j);
		//print_key();
	}
}
void print_key() {
	int i,j;
	for (i = 0; i < record_num; i++) {
		for (j = 0; j < field_num; j++) {
			printf("%d ",key[i].field[j]);
		}
		printf("\n");
	}
}
int insertion_sort(int f) {
	int i,j;
	Key temp;
	for (i = 1; i < record_num; i++) {
		temp = key[i];
		for (j = i-1; j >= 0;j--) {
			if (key[j].field[f] > temp.field[f]) {
				key[j + 1] = key[j];
				
			} 
			else{
				break;
			}
		}
		key[j + 1] = temp;
	}
}