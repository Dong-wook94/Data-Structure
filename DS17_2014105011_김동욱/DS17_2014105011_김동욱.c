#include <stdio.h>

int **TCM;
int **RCM;
int file_input();
void closure(int vertex_num);
void print_result(int vertex_num);
int main() {
	int vertex_num;
	int i;

	vertex_num = file_input();
	closure(vertex_num);
	print_result(vertex_num);
	/*for (i = 0; i < vertex_num; i++) {
		printf("\nvertex %d : ", i);
		for (nextNode = vertex[i]; nextNode; nextNode = nextNode->next) {
			printf("%d ->", nextNode->vertex);
		}
	}*/
}

int file_input() {
	FILE *f;
	int vertex_num,i,j,input;
	f = fopen("input.txt", "r");

	fscanf(f, "%d", &vertex_num);
	TCM = (int**)malloc(sizeof(int*)*vertex_num);
	RCM = (int**)malloc(sizeof(int*)*vertex_num);

	for (i = 0; i < vertex_num; i++) {
		TCM[i] = (int*)malloc(sizeof(int)*vertex_num);
		RCM[i] = (int*)malloc(sizeof(int)*vertex_num);
		for (j = 0; j < vertex_num; j++) {
			TCM[i][j] = 0;
			if (i == j) {
				RCM[i][j] = 1;
			}
			else {
				RCM[i][j] = 0;
			}
			
		}
	}
	
	for (i = 0; i < vertex_num; i++) {
		for (j = 0; j < vertex_num; j++) {
			fscanf(f, "%d", &input);
			if (input == 1) {
				TCM[i][j] = 1;
				RCM[i][j] = 1;
			}
		}
	}

	return vertex_num;
}
void closure(int vertex_num) {
	int i, j, k;

	for (k = 0; k < vertex_num; k++) {
		for (i = 0; i < vertex_num; i++) {
			for (j = 0; j < vertex_num; j++) {
				TCM[i][j] = TCM[i][j] || (TCM[i][k] && TCM[k][j]);
				RCM[i][j] = RCM[i][j] || (RCM[i][k] && RCM[k][j]);
			}
		}
	}
}
void print_result(int vertex_num) {
	int i,j;

	printf("\nA+ :\n");
	for (i = 0; i < vertex_num; i++) {
		for (j = 0; j < vertex_num; j++) {
			printf("%d ", TCM[i][j]);
		}
		printf("\n");
	}
	printf("\nA* :\n");
	for (i = 0; i < vertex_num; i++) {
		for (j = 0; j < vertex_num; j++) {
			printf("%d ", RCM[i][j]);
		}
		printf("\n");
	}
}