#include <stdio.h>
#include <math.h>

#define MAX 99999
char arr1[MAX];
char arr2[MAX];
int *numarr1;
int *numarr2;
int *resultarr;
int cnt1;
int cnt2;
file_input() {
	FILE *f;
	int i, j;
	cnt1 = 0;
	cnt2 = 0;
	f = fopen("input.txt", "r");

	fgets(arr1, sizeof(arr1), f);
	for (i = 0; arr1[i]!='\n'&&arr1[i]!='\0'; i++) {
		cnt1++;
	}
	fgets(arr2, sizeof(arr2), f);
	for (i = 0; arr2[i] != '\n' && arr2[i] != '\0'; i++) {
		cnt2++;
	}
	numarr1 = (int*)malloc(sizeof(int)*cnt1);
	numarr2 = (int*)malloc(sizeof(int)*cnt2);
	resultarr = (int*)malloc(sizeof(int)*(cnt1 + cnt2));
	//printf("%d", cnt1);
	//printf("%d", cnt2);
	for (i = 0; i < cnt1; i++) {
		numarr1[i] = arr1[i]-'0';
		//printf("%d", numarr1[i]);
	}
	for (i = 0; i < cnt2; i++) {
		numarr2[i] = arr2[i] - '0';
		//printf("%d", numarr2[i]);
	}
	for (i = 0; i < cnt2+cnt1; i++) {
		resultarr[i] = 0;
	}
}
void mult_arr() {
	int i, j,k, index = 0;
	for (i = cnt1-1; i >=0; i--) {
		index = cnt1-1-i;
		for (j = cnt2-1; j >= 0; j--) {
			resultarr[index] = resultarr[index] + (numarr1[i] * numarr2[j]);
			for (k = 1; k <= cnt2;k++) {
				resultarr[index + k] = resultarr[index] / pow(10,k) + resultarr[index+k];
			}
			//resultarr[index - 1] = resultarr[index] / 10;
			resultarr[index] = resultarr[index] % 10;
			index++;
		}
	}
}
void print_result() {
	int i;
	int check = 0;
	for (i = cnt1 + cnt2 - 1; i >= 0; i--) {
		if (check == 0 && resultarr[i] == 0) {

		}
		else {
			check = 1;
			printf("%d", resultarr[i]);
		}
		

	}
}
int main() {
	//printf("!!!");
	file_input();
	//printf("!!");
	mult_arr();
	print_result();
	return 0;
}