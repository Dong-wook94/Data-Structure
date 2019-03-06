#include <stdio.h>
#include <stdlib.h>
void file_input();
int h_table_size;
int key_num;//키개수
int search_num;//search 개수
char input_key_string[1000];
char input_search_string[1000];
char key_string[1000][100];
char search_string[1000][100];
int *key_arr;
int *search_value_arr;
char hash_table_size;
int *hashtable;
void hash_process();
void search(int value);
void print_result();

int main() {
	file_input();
	hash_process();
	print_result();
}

void file_input() {
	FILE *f;
	int input,i,j,k;
	char check_space;
	f = fopen("input.txt", "r");

	fscanf(f, "%d %d %d ", &h_table_size, &key_num, &search_num);
	fgets(input_key_string, 1000, f);
	fgets(input_search_string, 1000, f);
	//printf("%s", input_key_string);
	key_arr = (int*)malloc(sizeof(int)*key_num);
	search_value_arr = (int*)malloc(sizeof(int)*search_num);
	hashtable = (int*)malloc(sizeof(int)*h_table_size);
	for (i = 0; i < h_table_size; i++) {
		hashtable[i] = -1;//초기화
	}
	j = 0;
	k = 0;
	for (i = 0; input_key_string[i] != '\n'; i++) {
		if (input_key_string[i] == ' ') {
			k = 0;
			j++;
		}
		else if (input_key_string[i] == '\n') {
			break;
		}
		else {
			key_string[j][k] = input_key_string[i];
			k++;
		}
	}
	
	for (i = 0; i < key_num; i++) {
		//printf("%s\n", key_string[i]);
		key_arr[i] = atoi(key_string[i]);
		//printf("%d\n", key_arr[i]);
	}
	j = 0;
	k = 0;
	for (i = 0; input_search_string[i] != '\n'; i++) {
		if (input_search_string[i] == ' ') {
			k = 0;
			j++;
		}
		else if (input_search_string[i] == '\n') {
			break;
		}
		else {
			search_string[j][k] = input_search_string[i];
			k++;
		}
	}
	
	for (i = 0; i < search_num; i++) {
		search_value_arr[i] = atoi(search_string[i]);
		//printf("%d\n", search_value_arr[i]);
	}
}

void hash_process() {
	int i,j;
	for (i = 0; i < key_num; i++) {
		j = 0;
		while (1) {
			if (hashtable[(key_arr[i] % h_table_size) + j] == -1) {
				hashtable[(key_arr[i] % h_table_size) + j] = key_arr[i];
				break;
			}
			else {
				j++;
			}
		}
	}
}
void search(int value) {
	int j;
	j = 0;
	while (1) {
		if (hashtable[(value % h_table_size) + j] == value) {
			printf("S");
			break;
		}
		else if (hashtable[(value % h_table_size) + j] == -1) {
			printf("F");
			break;
		}
		else {
			j++;
		}
	}
}
void print_result() {
	int i;
	printf("Hash Table:\n");
	for (i = 0; i < h_table_size; i++) {
		if (hashtable[i] == -1) {
			printf("%d:\n", i);
		}
		else {
			printf("%d: %d\n", i, hashtable[i]);
		}

	}
	printf("\nSearch\n");
	for (i = 0; i < search_num; i++) {
		search(search_value_arr[i]);
	}
	printf("\n");
}