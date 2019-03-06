#include <stdio.h>
#define MAX_INT 100000
int num[MAX_INT];

void sort(int count) {
	int i, j;
	int temp;
	for (i = 0; i < count; i++) {
		//printf("%d ", num[i]);
	}
	for (i = 0; i < count; i++) {
		for (j = 0; j < count; j++) {
			if (num[i] < num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	for (i = 0; i < count; i++) {
		//printf("%d ", num[i]);
	}
	printf("%d\n%d", num[0], num[count - 1]);
}
int main() {
	FILE *f;
	
	int count = 0;
	
	f = fopen("input.txt", "r");

	while (!feof(f)) {
		fscanf(f, "%d", &num[count]);
		count++;
	}
	
	sort(count);

	fclose(f);

}