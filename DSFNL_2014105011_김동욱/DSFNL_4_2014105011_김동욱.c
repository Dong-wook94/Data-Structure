#include <stdio.h>
#define INFI 200000

typedef struct EDGE {
	int u;
	int v;
	int cost;
}EDGE;

EDGE *edge;
int vertex_num;
int start_vertex;
int dest_vertex;
int num_edge;
int **cost;
int *found;
int *distance;
int *touch;
int *path;

void init_matrix();
void file_input();
void find_shortest_path(int start_vertex);
void print_path();
int main() {
	int i;

	file_input();

	for (i = 0; i < num_edge; i++) {
		printf("%d %d %d %d\n", i, edge[i].u, edge[i].v, edge[i].cost);

	}
	find_shortest_path(start_vertex);
	printf("Distance: %d", distance[dest_vertex]);
	printf("\nPath: ");
	print_path();
}
void init_matrix() {
	int i, j;
	cost = (int**)malloc(sizeof(int*)*vertex_num);
	for (i = 0; i < vertex_num; i++) {
		cost[i] = (int*)malloc(sizeof(int)*vertex_num);
	}
	found = (int*)malloc(sizeof(int)*vertex_num);
	distance = (int*)malloc(sizeof(int)*vertex_num);
	touch = (int*)malloc(sizeof(int)*vertex_num);
	path = (int*)malloc(sizeof(int)*vertex_num);
	for (i = 0; i < vertex_num; i++) {
		found[i] = 0;
		distance[i] = -1;
		touch[i] = -1;
		for (j = 0; j < vertex_num; j++) {
			if (i == j)
				cost[i][j] = 0;
			else {
				cost[i][j] = INFI;
			}
		}
	}
}
void file_input() {
	FILE *f;
	int i, j;
	int input;
	f = fopen("input.txt", "r");

	fscanf(f, "%d %d %d", &vertex_num, &start_vertex, &dest_vertex);
	edge = (EDGE*)malloc(sizeof(EDGE)*vertex_num*(vertex_num - 1) / 2);
	init_matrix();
	for (i = 0; i < vertex_num; i++) {
		for (j = 0; j < vertex_num; j++) {
			fscanf(f, "%d", &input);
			if (input != 0) {
				cost[i][j] = input;
			}
		}
	}

	fclose(f);
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
	int i, u, w;
	for (i = 0; i < vertex_num; i++) {
		distance[i] = cost[start_vertex][i];
		if (distance[i] < INFI&&i != start_vertex)
			touch[i] = start_vertex;
	}
	found[start_vertex] = 1;
	for (i = 0; i < vertex_num; i++) {
		u = choose();
		found[u] = 1;
		for (w = 0; w < vertex_num; w++) {
			if (!found[w]) {
				if (distance[u] + cost[u][w] < distance[w]) {
					distance[w] = distance[u] + cost[u][w];
					touch[w] = u;
				}
			}
		}
	}
	/*for (i = 0; i < vertex_num; i++) {
	printf("%d ", distance[i]);
	}*/
	/*for (i = 0; i < vertex_num; i++) {
	printf("\ntouch %d: %d",i, touch[i]);
	}*/

}

void print_path() {
	int t;
	int i, cnt = 0;
	t = dest_vertex;
	while (1) {
		path[cnt] = t;
		cnt++;
		t = touch[t];
		if (t == -1)
			break;
	}
	for (i = cnt - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
}