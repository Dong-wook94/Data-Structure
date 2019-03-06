#include <stdio.h>
#define INFI 99999
#define FALSE 0
#define TRUE 1
typedef struct EDGE {
	int u;
	int v;
	int cost;
}EDGE;

EDGE *edge;
int vertex_num;
int start_vertex;
int num_edge;
int **cost;
int *found;
int *distance;

void init_matrix();
int file_input();
void find_shortest_path(int start_vertex);

int main() {
	int i;
	int start_vertex;
	start_vertex = file_input();

	for (i = 0; i < num_edge; i++) {
		printf("%d %d %d %d\n", i, edge[i].u, edge[i].v, edge[i].cost);

	}
	find_shortest_path(start_vertex);
}
void init_matrix() {
	int i,j;
	cost = (int**)malloc(sizeof(int*)*vertex_num);
	for (i = 0; i < vertex_num; i++) {
		cost[i] = (int*)malloc(sizeof(int)*vertex_num);
	}
	found = (int*)malloc(sizeof(int)*vertex_num);
	distance = (int*)malloc(sizeof(int)*vertex_num);
	for (i = 0; i < vertex_num; i++) {
		found[i] = FALSE;//초기화
		distance[i] = -1;//초기화
		for (j = 0; j < vertex_num; j++) {
			if (i == j)
				cost[i][j] = 0;
			else {
				cost[i][j] = INFI;//무한대
			}
		}
	}
}
int file_input(){
	FILE *f;
	int i,j;
	int input;
	int start_vertex;
	f = fopen("input.txt", "r");
	
	fscanf(f, "%d %d", &vertex_num, &start_vertex);
	edge = (EDGE*)malloc(sizeof(EDGE)*vertex_num*(vertex_num - 1) / 2);
	init_matrix();
	for (i = 0; i < vertex_num; i++) {
		for (j = 0; j < vertex_num; j++) {
			fscanf(f, "%d", &input);
			if (input != 0) {
				cost[i][j] = input;//값 입력
			}
		}
	}

	fclose(f);
	return start_vertex;
}
int choose() {
	int i, min, minpos;
	min = INFI;
	minpos = -1;
	for (i = 0; i < vertex_num; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}
void find_shortest_path(int start_vertex) {
	int i,u,w;
	for (i = 0; i < vertex_num; i++) {
		distance[i] = cost[start_vertex][i];
	}
	found[start_vertex] = TRUE;
	for (i = 0; i < vertex_num; i++) {
		u = choose();
		found[u] = TRUE;
		for (w = 0; w < vertex_num; w++) {
			if (!found[w]) {
				if (distance[u] + cost[u][w] < distance[w]) {
					distance[w] = distance[u] + cost[u][w];
				}
			}
		}
	}
	for (i = 0; i < vertex_num; i++) {
		printf("%d ", distance[i]);
	}
}