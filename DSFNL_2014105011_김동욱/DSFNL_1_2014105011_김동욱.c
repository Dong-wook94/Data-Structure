#include <stdio.h>
void file_input();
void sort_arr();
int sum();
int cnt;
int arr[999];
int main() {
	int average;
	file_input();
	sort_arr();
	average = sum();
	average = average / cnt;
	printf("Median : %d", arr[cnt / 2]);
	printf("\nAverage : %d\n", average);
}
void file_input() {
	FILE *f;
	cnt = 0;
	f = fopen("input.txt", "r");
	while (!feof(f)) {
		fscanf(f, "%d", &arr[cnt++]);
	}

}
void sort_arr() {
	int i, j;
	int temp;
	for (i = 0; i < cnt; i++) {
		for (j = i; j < cnt; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
int sum() {
	int i,total=0;
	for (i = 0; i < cnt; i++) {
		total += arr[i];
	}
	return total;
}