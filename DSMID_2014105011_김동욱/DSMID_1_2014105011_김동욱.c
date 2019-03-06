#include <stdio.h>

int main() {
	FILE *f;
	int num[3];
	int first;
	int i, j, temp;
	f = fopen("input.txt", "r");

	fscanf(f, "%d %d %d", &num[0], &num[1], &num[2]);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (num[i] < num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	printf("%d", num[1]);

	fclose(f);

}