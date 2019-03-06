#include <stdio.h>
#define FALSE 0
#define TRUE 1
typedef struct node *listPointer;
typedef struct node {
	int vertex;
	listPointer link;
}node;
typedef struct queue *queuePointer;
typedef struct queue {
	int vertex;
	queuePointer link;
}queue;
queuePointer front, rear;

listPointer *graph;
int *visited;
int file_input() {
	FILE *f;
	int num,i,j,input;
	listPointer temp,nextNode;
	f = fopen("input.txt", "r");

	fscanf(f, "%d", &num);
	graph = (listPointer*)malloc(sizeof(listPointer)*num);
	visited = (int*)malloc(sizeof(int)*num);
	for (i = 0; i < num; i++) {
		graph[i] = (node*)malloc(sizeof(node)*num);
		graph[i]->link = NULL;
		//visited[i] = FALSE;
	}
	if (!feof(f)) {
		for (i = 0; i < num; i++) {
			nextNode = graph[i];
			for (j = 0; j < num; j++) {
				fscanf(f, "%d", &input);
				if (input == 1) {
					temp = (node*)malloc(sizeof(node)*num);
					temp->vertex = j;
					temp->link = NULL;
					nextNode->link = temp;
					nextNode = nextNode->link;
				}
				
			}
		}
	}
	return num;
}

void print_adjacency_vertex(int num) {
	int i, j;
	listPointer nextNode;
	for (i = 0; i < num; i++) {
		printf("VERTEX %d :",i);
		for (nextNode = graph[i]->link; nextNode; nextNode = nextNode->link) {
			printf(" %d", nextNode->vertex);
		}
		printf("\n");
	}
}
void set_visited_false(int num) {
	int i;
	for (i = 0; i < num; i++) {
		visited[i] = FALSE;
	}
}
void dfs(int v) {
	listPointer w;
	visited[v] = TRUE;
	printf("%2d", v);
	for (w = graph[v]->link; w; w=w->link) {
		if (!visited[w->vertex])
			dfs(w->vertex);
	}
}
void addq(int num) {
	rear->link = (queue*)malloc(sizeof(queue));
	rear->link->vertex = num;
	rear->link->link = NULL;
	rear = rear->link;
}
int deleteq() {
	int vertex;
	vertex = front->link->vertex;
	front = front->link;
	return vertex;
}
void bfs(int v) {
	listPointer w;
	visited[v] = TRUE;
	front = (queue*)malloc(sizeof(queue));
	front->link = NULL;
	rear = front;
	addq(v);
	printf("%2d", v);
	while (front->link) {
		v = deleteq();
		for (w = graph[v]->link; w; w=w->link) {
			if (!visited[w->vertex]) {
				printf("%2d", w->vertex);
				addq(w->vertex);
				visited[w->vertex] = TRUE;
			}
		}
	}
}
int main() {
	int num;
	num = file_input();
	print_adjacency_vertex(num);
	set_visited_false(num);
	printf("DFS : ");
	dfs(0);
	set_visited_false(num);
	printf("\nBFS : ");
	bfs(0);
	printf("\n");
	return 0;
}