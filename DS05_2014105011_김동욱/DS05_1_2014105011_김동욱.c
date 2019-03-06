#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101

typedef struct {
	int col;
	int row;
	int value;
}term;
term a[MAX_TERMS];
term *b;
int **mat1;
int **mat2;
int m, n;
int *startingPos;
int *rowTerms;
void creat_matrix() {
	FILE *f_mat1;
	FILE *f_mat2;

	int i, j;
	int m2, n2;
	f_mat1 = fopen("mat1.txt", "r");
	fscanf(f_mat1, "%d %d", &m, &n);
	mat1 = (int**)malloc(sizeof(int*)*m);
	for (int i = 0; i < m; i++)
	{
		mat1[i] = (int*)malloc(sizeof(int)*n);
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			fscanf(f_mat1, "%d", &mat1[i][j]);
		}
	}
	fclose(f_mat1);
	f_mat2 = fopen("mat2.txt", "r");
	fscanf(f_mat2, "%d %d", &m2, &n2);

	if (m != m2 || n != n2)
	{
		printf("row 와 col은 두행렬간의 값이 같아야합니다!");
		return 0;
	}
	mat2 = (int**)malloc(sizeof(int*)*m);
	for (int i = 0; i < m; i++)
	{
		mat2[i] = (int*)malloc(sizeof(int)*n);
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			fscanf(f_mat2, "%d", &mat2[i][j]);
		}
	}
	rowTerms = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		rowTerms[i] = 0;
	}
	startingPos = (int*)malloc(sizeof(int)*n);
}
int sum_matrix() {
	int i, j;
	int term_num = 1;
	a[0].row = m;
	a[0].col = n;
	a[0].value = 0;
	for (i = 0; i < a[0].row; i++) {
		for (j = 0; j < a[0].col; j++) {
			if (mat1[i][j] != 0 || mat2[i][j] != 0) {
				a[term_num].row = i;
				a[term_num].col = j;
				a[term_num].value = mat1[i][j] + mat2[i][j];
				//printf("(%d,%d,%d)\n", a[term_num].row, a[term_num].col, a[term_num].value);
				a[0].value++;
				rowTerms[j]++;
				term_num++;
			}
		}
	}
	startingPos[0] = 1;
	printf("Matrix Addition :\n");
	for (i = 0; i < term_num; i++) {
		printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);
	}
	for (i = 1; i < n; i++) {
		startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
	}
	return term_num;
}
void transpose_matrix(int term_num) {
	int i;
	b[0].col = a[0].row;
	b[0].row = a[0].col;
	b[0].value = a[0].value;
	//printf("!!!\n");
	for (i = 1; i < term_num; i++) {
		b[startingPos[a[i].col]].col = a[i].row;
		b[startingPos[a[i].col]].row = a[i].col;
		b[startingPos[a[i].col]].value = a[i].value;
		//printf("%d %d %d %d\n", startingPos[a[i].col],b[startingPos[a[i].col]].row, b[startingPos[a[i].col]].col, b[startingPos[a[i].col]].value);
		startingPos[a[i].col]++;
	}

}
int main() {
	int term_num, i;
	creat_matrix();
	term_num = sum_matrix();
	b = (term*)malloc(sizeof(term)*term_num);
	transpose_matrix(term_num);
	printf("\nTransPos Matrix:\n");
	for (i = 0; i < term_num; i++) {
		printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
	}
	return 0;
}