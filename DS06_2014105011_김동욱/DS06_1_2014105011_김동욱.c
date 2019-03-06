#include <stdio.h>

#define MAX_LENGTH 100

void nfind();
void file_input();
char string[MAX_LENGTH];
char pat[MAX_LENGTH];
int find_string_length();
int find_pat_length();

int main() {

	file_input();
	nfind();


}

void file_input() {
	FILE *f;

	f = fopen("input.txt", "r");

	fgets(string, sizeof(string), f);
	fgets(pat, sizeof(pat), f);

	printf("string : ");
	puts(string);
	printf("pat : ");
	puts(pat);
	fclose(f);
}
void nfind() {
	int i, j;
	int string_len, pat_len;
	int check = 0;
	string_len = find_string_length();
	pat_len = find_pat_length();
	for (i = 0; i <= string_len; i++) {
		for (j = 0; j < pat_len; j++)
		{
			if (string[i + j] != pat[j]) {
				check = 0;
				break;
			}

			else
			{
				check++;
			}
		}
		if (check == pat_len)
			break;

	}

	if (i == string_len)
		printf("\nÀÏÄ¡x\n");
	else
		printf("\nThe pattern test is found at the position %d\n", i);
}
int find_string_length() {
	int i;
	int cnt = 0;
	for (i = 0; i < string[i] != NULL; i++) {
		cnt++;
	}
	return cnt;
}
int find_pat_length() {
	int i;
	int cnt = 0;
	for (i = 0; i < pat[i] != '\0' && pat[i] != '\n'; i++) {
		cnt++;
	}
	//printf("cnt = %d", cnt);
	return cnt;
}