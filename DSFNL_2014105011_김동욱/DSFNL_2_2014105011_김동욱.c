#include <stdio.h>
#include <stdlib.h>
void file_input();
int bucket_num;
char input[999];
int cnt;
int sum_input();
int main() {
	file_input();
	//printf("%d",'z'-96);
	printf("%d\n", sum_input()%bucket_num);
}

void file_input() {
	FILE *f;
	int i;
	cnt = 0;
	f = fopen("input.txt", "r");

	fscanf(f, "%d ", &bucket_num);
	
	fgets(input,999,f);
	for (i = 0; input[i]||input[i]=='\n'; i++) {
		//printf("%d %c\n", i, input[i]);
	}
	cnt = i;
}
int sum_input() {
	int i;
	int total=0;
	for (i = 0; i < cnt; i++) {
		total += input[i] - 96;
	}
	return total;
}