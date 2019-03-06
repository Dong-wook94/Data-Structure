#include <stdio.h>
#define MAX_STACK_SIZE 100
typedef struct Stack{
	char key[MAX_STACK_SIZE];
	int ptr;
}Stack;
Stack stack;
typedef struct Stack_post {
	int key[MAX_STACK_SIZE];
	int ptr;
}Stack_post;

Stack_post stack_p;
char arr[MAX_STACK_SIZE];
int arr_cnt = 0;
void stack_push(char input) {
	stack.key[++stack.ptr]=input;
}
char stack_pop() {
	//printf("%c ", stack.key[stack.ptr]);
	//arr[arr_cnt++] = stack.key[stack.ptr];
	return stack.key[stack.ptr--];
}
char stack_top() {
	return stack.key[stack.ptr];
}
void pstack_push(int input) {
	stack_p.key[++stack_p.ptr] = input;
}
char pstack_pop() {
	//printf("%c ", stack.key[stack.ptr]);
	//arr[arr_cnt++] = stack_p.key[stack_p.ptr];
	return stack_p.key[stack_p.ptr--];
}
char pstack_top() {
	return stack_p.key[stack_p.ptr];
}
void file_input() {
	FILE *f;
	char input, oper;
	f = fopen("input.txt", "r");
	stack.ptr = -1;
	while (!feof(f)) {
		fscanf(f, "%c ", &input);
		switch (input)
		{
		case '(':
			stack_push(input);
			break;
		case ')':
			while (1) {
				oper = stack_pop();
				if (oper == '(')
					break;
				else
				{
					printf("%c ", oper);
					arr[arr_cnt++] = oper;
				}
			}
			break;
		case '+':
			while (stack_top() == '+' || stack_top() == '-' || stack_top() == '/' || stack_top() == '*' || stack_top() == '%' || stack_top() == '^') {
				oper = stack_pop();
				printf("%c ", oper);
				arr[arr_cnt++] = oper;
			}
			stack_push('+');

			break;
		case '-':
			while (stack_top() == '+' || stack_top() == '-' || stack_top() == '/' || stack_top() == '*' || stack_top() == '%' || stack_top() == '^') {
				oper = stack_pop();
				printf("%c ", oper);
				arr[arr_cnt++] = oper;
			}
			stack_push('-');
			break;
		case '/':
			while (stack_top() == '/' || stack_top() == '*' || stack_top() == '%' || stack_top() == '^') {
				oper = stack_pop();
				printf("%c ", oper);
				arr[arr_cnt++] = oper;
			}
			stack_push('/');
			break;
		case '*':
			while (stack_top() == '/' || stack_top() == '*' || stack_top() == '%' || stack_top() == '^') {
				oper = stack_pop();
				printf("%c ", oper);
				arr[arr_cnt++] = oper;
			}
			stack_push('*');
			break;
		case '%':
			while (stack_top() == '/' || stack_top() == '*' || stack_top() == '%' || stack_top() == '^') {
				oper = stack_pop();
				printf("%c ", oper);
				arr[arr_cnt++] = oper;
			}
			stack_push('%');
			break;
		case '^':
			while (stack_top() == '^') {
				oper = stack_pop();
				printf("%c ", oper);
				arr[arr_cnt++] = oper;
			}
			stack_push('^');
			break;

		default:
			printf("%c ", input);
			arr[arr_cnt++] = input;
			break;
		}
	}
	while (stack.ptr >-1) {
		oper = stack_pop();
		printf("%c ", oper);
		arr[arr_cnt++] = oper;
	}
	printf("\n");
	fclose(f);
}
void postfix() {
	int i,j;
	char input;
	char num1,num2;
	int result;
	stack_p.ptr = -1;
	for (i = 0; i < arr_cnt; i++) {
		input = arr[i];
		if (input >= '0' &&input <= '9') {
			pstack_push(input - '0');
		}
		else {
			switch (input)
			{
			case '(':
				break;
			case ')':
				break;
			case '+':
				num2 = pstack_pop();
				num1 = pstack_pop();
				result = num1 + num2;
				pstack_push(result);
				break;
			case '-':
				num2 = pstack_pop();
				num1 = pstack_pop();
				result = num1 - num2;
				pstack_push(result);
				break;
			case '/':
				num2 = pstack_pop();
				num1 = pstack_pop();
				result = num1 / num2;
				pstack_push(result);
				break;
			case '*':
				num2 = pstack_pop();
				num1 = pstack_pop();
				result = num1 * num2;
				pstack_push(result);
				break;
			case '%':
				num2 = pstack_pop();
				num1 = pstack_pop();
				result = num1 % num2;
				pstack_push(result);
				break;
			case '^':
				num2 = pstack_pop();
				num1 = pstack_pop();
				result = num1;
				for (j = 1; j < num2; j++) {
					result *= num1;
				}
				pstack_push(result);
				break;
			default:
				break;
			}
		}

	}
	if (stack.ptr >-1) {
		printf("¿À·ù");
	}
	printf("%d\n",result);
}
int main() {
	file_input();
	postfix();
}


