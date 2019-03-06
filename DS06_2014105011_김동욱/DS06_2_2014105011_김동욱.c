#include <stdio.h>
#define MAX_LENGTH 1000

void failure_function(int str_len);
void file_input();
char string[MAX_LENGTH];
char pat[MAX_LENGTH];
int find_string_length();
int find_pat_length();
int fail[MAX_LENGTH] = { 0, };
void pmatch(int str_len, int pat_len);
void print_failure(int pat_len) {
	int i, j;
	printf("Failure function:\n");
	printf("j    ");
	for (i = 0; i < pat_len; i++) {
		printf("%5d", i);
	}
	printf("\npat  ");
	for (i = 0; i < pat_len; i++) {
		printf("%5c", pat[i]);
	}

	printf("\nf    ");
	for (i = 0; i < pat_len; i++) {
		printf("%5d", fail[i]);
	}


}
int main() {
	int a, i, j;
	int str_len, pat_len;
	file_input();
	pat_len = find_pat_length();
	str_len = find_string_length();
	failure_function(str_len);
	print_failure(pat_len);
	pmatch(str_len, pat_len);
}

void pmatch(int str_len, int pat_len) {
	int i = 0, j = 0,k,check=0;

	while (i < str_len) {
		check = 0;
		if (string[i+j] == pat[j]) {//비교하고
			if (j == pat_len - 1)
				break;
			else {
				j++;
			}
		}
		else  {
			for (k = 0; k < j; k++)
			{
				if (fail[k] == 0){
					i = i + k;
					check = 1;
					j = 0;
					break;
				}

			}
			if (check == 0) {
				i++;
				j = 0;
			}
		}
	}
	if (i == str_len)
		printf("\n일치x\n");
	else
		printf("\nThe pattern test is found at the position %d\n", i);
}

void failure_function(int str_len) {
	int i, j;
	fail[0] = -1;
	for (i = 1; i < str_len; i++) {
		j = fail[i - 1] + 1;
		while (pat[i] != pat[j] && j > 0) {
			j = fail[j - 1] + 1;
		}
		if (pat[i] == pat[j]) {
			fail[i] = j;
		}
		else {
			fail[i] = -1;
		}
	}
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
	for (i = 0; i < pat[i] != '\0' && pat[i] != '\n'&& pat[i] != '\r'; i++) {
		cnt++;
	}
	//printf("cnt = %d", cnt);
	return cnt;
}
void file_input() {
	FILE *f;

	f = fopen("input.txt", "r");

	fgets(string, sizeof(string), f);
	fgets(pat, sizeof(pat), f);

	/*printf("string : ");
	puts(string);
	printf("pat : ");
	puts(pat);*/
	fclose(f);
}