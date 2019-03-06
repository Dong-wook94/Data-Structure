#include <stdio.h>

#define MAX_DEGREE 1001
typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

int main() {

	FILE *fa;
	FILE *fb;
	int numa,numb;
	int i;
	float coefficient;
	int exponent;
	polynomial poly_sum;
	int fcheck=0;

	for (i = 0; i < MAX_DEGREE; i++) {
		poly_sum.coef[i] = 0;
	}
	fa = fopen("a.txt", "r");

	fscanf(fa, "%d", &numa);
	poly_sum.degree = 0;
	for (i = 0; i < numa; i++) {
		fscanf(fa, "%f", &coefficient);
		fscanf(fa, "%d", &exponent);
		if (exponent > poly_sum.degree)
			poly_sum.degree = exponent;
		poly_sum.coef[exponent] += coefficient;
	}
	fclose(fa);
	fb = fopen("b.txt", "r");
	fscanf(fb, "%d", &numb);

	for (i = 0; i < numb; i++) {
		fscanf(fb, "%f", &coefficient);
		fscanf(fb, "%d", &exponent);
		if (exponent > poly_sum.degree)
			poly_sum.degree = exponent;
		poly_sum.coef[exponent] += coefficient;
	}
	fclose(fb);
	//printf("%d", poly_sum.degree);
	for (i = poly_sum.degree; i>=0; i--) {
		if (poly_sum.coef[i] != 0)
		{
			if (fcheck == 0) {
				poly_sum.degree = i;
				fcheck = 1;
				printf("%.f", poly_sum.coef[i]);
				if (i != 0) {
					printf("x^%d ", i);
				}
			}
			else {

				printf("+ %.f", poly_sum.coef[i]);
				if (i != 0) {
					printf("x^%d ", i);
				}
			}
			
		}
		
	}


}