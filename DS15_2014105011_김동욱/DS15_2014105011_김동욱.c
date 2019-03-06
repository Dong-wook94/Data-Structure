#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

typedef struct element* HeapType;
typedef struct element {
	int key;
	int u;
	int v;
}element;
typedef struct disjoint_set {
	int cost;
	int u;
	int v;
	//int check;
}disjoint_set;
int n = 0; // Heap
FILE* fp;
int parent[MAX_VERTICES];
int nodenum;

void insert_heap_edge(HeapType h, int u, int v, int weight);
void insert_min_heap(HeapType h, element e);
void insert_all_edges(HeapType h,int num);
element delete_min_heap(HeapType h);
void set_init(int n, element e);
int find(int i);
void simpleunion(int i, int j);
void kruskal(int n);
disjoint_set *d_set;
int file_input() {
	FILE *f;

	int vertex_num, i, j, input;
	int cnt = 0;
	f = fopen("input.txt", "r");

	fscanf(f, "%d", &vertex_num);
	d_set = (disjoint_set*)malloc(sizeof(disjoint_set)*vertex_num*(vertex_num - 1) / 2);
	while (!feof(f)) {
		for (i = 0; i < vertex_num; i++) {
			for (j = 0; j < vertex_num; j++) {
				fscanf(f, "%d", &input);
				if (input != 0 && i < j) {
					d_set[cnt].cost = input;
					d_set[cnt].u = i;
					d_set[cnt].v = j;
					//d_set[cnt].check = FALSE;
					cnt++;
				}
			}
		}
	}
	return cnt;
}
int main()
{

	int n;
	n = file_input();

	kruskal(n);

	//fclose(fp);
	return 0;
}

void insert_min_heap(HeapType h, element e)
{
	int i;
	if (HEAP_FULL(n))
	{
		fprintf(stderr, "The heap is full.\n");
		exit(EXIT_FAILURE);
	}
	i = ++n;
	while ((i != 1) && (e.key < h[i / 2].key))
	{
		h[i] = h[i / 2];
		i /= 2;
	}
	h[i] = e;
}

void insert_heap_edge(HeapType h, int u, int v, int weight)
{
	element e;
	e.u = u;
	e.v = v;
	e.key = weight;
	insert_min_heap(h, e);
	set_init(n, e);
}

void insert_all_edges(HeapType h, int num)
{
	int i, cnt = 0;
	int v1, v2, value;
	for(i=0;i<num;i++)
	{
		insert_heap_edge(h, d_set[i].u, d_set[i].v, d_set[i].cost);
	}

	for (i = 0; i < MAX_VERTICES; i++)
	{
		if (parent[i] == -1)
			cnt++;
	}
	nodenum = cnt;

}

element delete_min_heap(HeapType h)
{
	int parent, child;
	element item, temp;
	if (HEAP_EMPTY(n))
	{
		fprintf(stderr, "The heap is empty\n");
		exit(EXIT_FAILURE);
	}
	item = h[1];
	temp = h[(n)--];
	parent = 1;
	child = 2;
	while (child <= n)
	{
		if ((child < n) && (h[child].key > h[child + 1].key))
			child++;
		if (temp.key <= h[child].key)
			break;
		h[parent] = h[child];
		parent = child;
		child *= 2;
	}
	h[parent] = temp;
	return item;
}

void set_init(int n, element e)
{
	parent[e.u] = -1;
	parent[e.v] = -1;
}

int find(int i)
{
	for (; parent[i] >= 0; i = parent[i])
		;
	return i;
}

void simpleunion(int i, int j)
{
	parent[i] = j;
}

void kruskal(int num)
{
	int sum = 0;
	int check=0;
	int edge_accepted = 0;
	HeapType h = (HeapType)malloc(sizeof(element)*num);
	int uset, vset;
	element e;
	//init(h, n);
	insert_all_edges(h,num);
	//set_init(n);
	printf("Selected Edges: ");
	while (edge_accepted < (nodenum - 1))
	{
		e = delete_min_heap(h);
		uset = find(e.u);
		vset = find(e.v);
		if (uset != vset)
		{
			if (check == 1) {
				printf(", ");
			}
			printf("(%d,%d)", e.u, e.v);
			check = 1;
			sum += e.key;
			edge_accepted++;
			simpleunion(uset, vset);
		}
	}

	printf("\ncost : %d", sum);
}