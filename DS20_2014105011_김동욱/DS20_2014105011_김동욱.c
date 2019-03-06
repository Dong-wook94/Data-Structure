#include <stdio.h>
typedef struct Key {
	int k1;
	int k2;
}Key;
Key *key;
int *link;
int record_num;

void init_linkarr();
void file_input();
void merge(Key initList[],Key mergedList[], int i, int m ,int n,int keyarr);
void mergePass(Key initList[], Key mergedList[], int s, int keyarr);
void iterative_merge_sort(int keyarr);
int listMerge(int start1, int start2, int keyarr);
int recursive_merge_sort(int left, int right, int keyarr);
void print_key();
void print_recursive(int i);
int main() {
	file_input();
	int left,i;
	printf("Iterative Merge Sort\n");
	iterative_merge_sort(1);

	printf("Key: K1\n");
	print_key();
	iterative_merge_sort(2);

	printf("Key: K2\n");
	print_key();
	printf("\nRevursive Merge Sort\n");
	
	printf("Key: K1\n");
	init_linkarr();
	left = recursive_merge_sort(1, record_num, 1);
	print_recursive(left);
	
	printf("Key: K2\n"); 
	init_linkarr();
	left = recursive_merge_sort(1, record_num, 2);
	print_recursive(left);
}
void init_linkarr() {
	int i;
	for (i = 1; i <= record_num; i++) {
		link[i] = 0;
	}
}
void file_input() {
	FILE *f;
	int i;
	f = fopen("input.txt", "r");

	fscanf(f, "%d", &record_num);
	key = (Key*)malloc(sizeof(Key)*record_num + 1);
	link = (int*)malloc(sizeof(int)*record_num + 1);
	for (i = 1; i <= record_num; i++) {
		fscanf(f, "%d %d", &key[i].k1, &key[i].k2);
	}

}
void merge(Key initList[], Key mergedList[], int i, int m,int n,int keyarr) {
	int j, k, t;
	j = m + 1;
	k = i;

	while (i <= m&&j <= n) {
		if (keyarr == 1) {
			if (initList[i].k1 <= initList[j].k1)
				mergedList[k++] = initList[i++];
			else
				mergedList[k++] = initList[j++];
		}
		else {
			if (initList[i].k2 <= initList[j].k2)
				mergedList[k++] = initList[i++];
			else
				mergedList[k++] = initList[j++];
		}

	}
	if (i > m) {
		for (t = j; t <= n; t++)
			mergedList[t] = initList[t];
	}
	else{
		for (t = i; t <= m; t++)
			mergedList[k + t - i] = initList[t];
	}



}
void mergePass(Key initList[], Key mergedList[], int s,int keyarr) {
	int i, j;
	for (i = 1; i < record_num - 2 * s + 1; i += 2 * s) {
		merge(initList, mergedList, i, i + s - 1, i + 2 * s - 1, keyarr);
	}
	if (i + s - 1 < record_num) {
		merge(initList, mergedList, i, i + s - 1, record_num, keyarr);
	}
	else {
		for (j = i; j <= record_num; j++)
			mergedList[j] = initList[j];
	}
}
void iterative_merge_sort(int keyarr) {
	Key *extra;
	int segment_size=1;
	extra = (Key*)malloc(sizeof(Key)*record_num + 1);

	while (segment_size < record_num) {
		mergePass(key, extra, segment_size,keyarr);
		segment_size *= 2;
		mergePass(extra, key, segment_size, keyarr);
		segment_size *= 2;
	}
}
int listMerge(int start1, int start2,int keyarr) {
	int last1, last2, lastResult = 0;
	for (last1 = start1, last2 = start2; last1&&last2;) {
		if (keyarr == 1) {
			if (key[last1].k1 <= key[last2].k1) {
				link[lastResult] = last1;
				lastResult = last1;
				last1 = link[last1];
			}
			else {
				link[lastResult] = last2;
				lastResult = last2;
				last2 = link[last2];
			}
		}
		else {
			if (key[last1].k2 <= key[last2].k2) {
				link[lastResult] = last1;
				lastResult = last1;
				last1 = link[last1];
			}
			else {
				link[lastResult] = last2;
				lastResult = last2;
				last2 = link[last2];
			}
		}
		
	}
	if (last1 == 0)
		link[lastResult] = last2;
	else
		link[lastResult] = last1;
	return link[0];
}
int recursive_merge_sort(int left, int right,int keyarr) {
	int mid;
	if (left >= right)
		return left;
	mid = (left + right) / 2;
	return listMerge(recursive_merge_sort(left, mid,keyarr), recursive_merge_sort(mid + 1, right,keyarr),keyarr);
}
void print_key() {
	int i;

	for (i = 1; i <= record_num; i++) {
		printf("%d %d\n", key[i].k1, key[i].k2);
	}
}
void print_recursive(int i) {
	while (1)
	{
		if (i == 0)
			break;
		printf("%d %d\n", key[i].k1, key[i].k2);
		i = link[i];
	}
}