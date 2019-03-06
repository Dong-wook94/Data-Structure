#include <stdio.h>

#define MAX_TERMS 1000
typedef struct {
	float coef;
	int expon;
}polynomial;
polynomial terms[MAX_TERMS];
void selection_sort(int num) {
	int i, j;
	int max;
	polynomial temp;
	for (i = 0; i < num - 1; i++) {
		max = i;
		for (j = i + 1; j < num; j++) {
			if (terms[j].expon > terms[max].expon)
				max = j;
		}
		temp = terms[i];
		terms[i] = terms[max];
		terms[max] = temp;
	}
}
int main() {
	FILE *fa;
	FILE *fb;
	int numa, numb;
	float coefficient;
	int exponent;
	int i, j;
	int fcheck = 0;
	int check_in;
	int term_num = 0;

	for (i = 0; i < MAX_TERMS; i++) {
		terms[i].coef = 0;
		//terms[i].expon = i;
	}
	fa = fopen("a.txt", "r");

	fscanf(fa, "%d", &numa);
	for (i = 0; i < numa; i++) {
		fscanf(fa, "%f", &coefficient);
		fscanf(fa, "%d", &exponent);
		terms[i].coef += coefficient;
		terms[i].expon = exponent;
	}
	term_num = i;
	fclose(fa);
	fb = fopen("b.txt", "r");
	fscanf(fb, "%d", &numb);
	for (i = 0; i <numb; i++) {
		fscanf(fb, "%f", &coefficient);
		fscanf(fb, "%d", &exponent);
		check_in = 0;
		for (j = 0; j < numa; j++) {
			if (exponent == terms[j].expon) {
				terms[j].coef += coefficient;
				check_in = 1;
			}
		}
		if (check_in == 0) {
			terms[term_num].coef += coefficient;
			terms[term_num].expon = exponent;
			term_num++;
		}

	}
	fclose(fb);
	selection_sort(term_num);
	for (i = 0; i < term_num; i++) {
		if (fcheck == 0) {
			fcheck = 1;
			printf("%.f", terms[i].coef);
			if (terms[i].expon != 0) {
				printf("x^%d ", terms[i].expon);
			}
		}
		else {

			printf("+ %.f", terms[i].coef);
			if (terms[i].expon != 0) {
				printf("x^%d ", terms[i].expon);
			}
		}
	}

}