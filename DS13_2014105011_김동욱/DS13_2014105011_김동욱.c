#include <stdio.h>
 
int element_num;
int pair_num;
int *count;
int *parent;
int *root;

void weight_union(int num1, int num2) {

	int temp,root;

	for (root = num1; parent[root] >= 0; root = parent[root]) {
	}
	num1 = root;
	for (root = num2; parent[root] >= 0; root = parent[root]) {
	}
	num2 = root;
	temp = parent[num1] + parent[num2];
	if (parent[num1] > parent[num2]) {
		parent[num1] = num2;
		parent[num2] = temp;
		count[num2] = -temp;
	}
	else {
		parent[num2] = num1;
		parent[num1] = temp;
		count[num1] = -temp;
	}
}
void file_input() {
	FILE *f;
	int i;
	f = fopen("input.txt", "r");
	int num1, num2;

	fscanf(f,"%d %d", &element_num, &pair_num);

	count = (int*)malloc(sizeof(int)*element_num);
	parent = (int*)malloc(sizeof(int)*element_num);
	root = (int*)malloc(sizeof(int)*element_num);

	for (i = 0; i < element_num; i++) {
		count[i] = 1;
		parent[i] = -count[i];
	}
	while (!feof(f)) {
		fscanf(f, "%d %d", &num1, &num2);
		weight_union(num1, num2);
	}
	/*for (i = 0; i < element_num; i++)
	{
		printf("%d parent : %d count :%d\n", i, parent[i], count[i]);
	}*/

	fclose(f);
}
void print_result() {
	int i, j;
	int cnt = 0, check = 0;

	for (i = 0; i < element_num; i++)
	{
		//printf("%d root : %d \n", i, collapsing_find(i));
		root[i] = collapsing_find(i);
	}

	for (i = 0; i < element_num; i++)
	{
		if (parent[i] < 0)
			cnt++;
	}
	printf("%d", cnt);
	for (i = 0; i < element_num; i++) {
		if (parent[i] < 0) {
			printf("\n{");
			for (j = 0; j < element_num; j++) {
				if (root[j] == i) {
					if (check == 0) {
						check = 1;
					}
					else {
						printf(", ");
					}

					printf("%d", j);
				}


			}
			check = 0;
			printf("}");
		}
	}
}

int collapsing_find(int num) {
	int root, trail, lead;
	for (root = num; parent[root] >= 0; root = parent[root]) {

	}//이걸로 해당 element가 포함된 곳의 root를 찾음
		

	
	for (trail = num; trail != root; trail = lead) {
		lead = parent[trail];
		parent[trail] = root;
	}
	return root;
}
int main() {
	
	file_input();
	print_result();

	
}