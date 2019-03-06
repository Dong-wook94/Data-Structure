#include <stdio.h>
int check_num;
void check_prime(int num) {
	int i;
	for (i = 2; i < num; i++) {
		if (num%i == 0)
		{
			return;
		}
	}
	check_num++;

}

int main() {
	FILE *f;
	int input;
	int i, j;
	f = fopen("input.txt", "r");
	fscanf(f, "%d", &input);

	if (input <= 1) {
		printf("1보다큰 자연수를 입력하시오");
		return 0;
	}
	check_num = 0;
	for (i = 2; i <= input; i++) {
		check_prime(i);
	}
	printf("%d", check_num);



	fclose(f);
}