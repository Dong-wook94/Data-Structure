#include <stdio.h>

typedef struct node *nodePointer;
typedef struct node {
	int vertex;
	nodePointer link;
}node;
typedef struct headnodes {
	int count;//얘는 이 vertex를 가리키고있는 차수
	nodePointer link;
}headnodes;
headnodes *graph;

nodePointer find_endpoint(int i);
int file_input();
void topsort(int num_vertex);
int main() {
	int num_vertex,i;
	nodePointer nextNode;

	num_vertex = file_input();

	/*for (i = 0; i < num_vertex; i++) {
		printf("\ngraph [%d](%d)->", i,graph[i].count);
		for (nextNode = graph[i].link; nextNode; nextNode = nextNode->link) {
			printf("%d->", nextNode->vertex);
		}
		
	}*/
	topsort(num_vertex);


}
nodePointer find_endpoint(int i) {
	nodePointer nextnode;
	for (nextnode = graph[i].link; nextnode->link; nextnode = nextnode->link) {

	}
	return nextnode;
}

int file_input() {
	FILE *f;
	int num_vertex,i,j,input;
	nodePointer temp,endNode;
	f = fopen("input.txt", "r");

	fscanf(f, "%d", &num_vertex);
	graph = (headnodes*)malloc(sizeof(headnodes)*num_vertex);
	for (i = 0; i < num_vertex; i++) {
		graph[i].count = 0;//count 초기화
		graph[i].link = NULL;
	}
	for (i = 0; i < num_vertex; i++) {
		for (j = 0; j < num_vertex; j++) {
			fscanf(f, "%d", &input);
			if (input == 1) {
				temp = (node*)malloc(sizeof(node));
				temp->vertex = j;
				temp->link = NULL;
				if (graph[i].link==NULL) {
					graph[i].link = temp;
					graph[j].count++;
				}
				else {
					endNode = find_endpoint(i);
					endNode->link = temp;
					graph[j].count++;
				}
			}
		}
	}
	return num_vertex;
}
void topsort(int num_vertex) {
	int i, j, k, top;
	nodePointer ptr;

	top = -1;
	for (i = 0; i < num_vertex; i++) {
		if (graph[i].count==0) {
			graph[i].count = top;
			top = i;
		}
	}
	for (i = 0; i < num_vertex; i++) {
		if (top == -1) {
			fprintf(stderr, "\n사이클이 존재합니다. sorting을 종료합니다.\n");
			exit(1);
		}
		else {
			j = top;
			top = graph[top].count;
			printf("%d ",j);
			for (ptr = graph[j].link; ptr; ptr = ptr->link) {
				k = ptr->vertex;
				graph[k].count--;
				if (graph[k].count == 0) {
					graph[k].count = top;
					top = k;
				}
			}
		}
	}
}
