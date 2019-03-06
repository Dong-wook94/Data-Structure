#include <stdio.h>
#include <stdlib.h>
typedef struct Stack {
	char data[100];
	int ptr;
}Stack;
Stack stack;
void stack_push(char input) {
	stack.data[++stack.ptr] = input;
}
int stack_empty() {
	if (stack.ptr == -1)
		return 1;
	else
		return 0;
}
char stack_pop() {
	return stack.data[stack.ptr--];
}
char stack_top() {
	return stack.data[stack.ptr];
}
int main() {
	FILE *f;
	char input;
	char a;
	f = fopen("input.txt", "r");
	stack.ptr = -1;
	//char stack_top_op;
	while (!feof(f)) {
		fscanf(f, "%c ", &input);
		//fflush();
		if (input == ' ')
			continue;
		else {
			switch (input) {
			case '+':
				if (stack_top() == '*'||stack_top() == '/'||stack_top()=='%' || stack_top() == '+' || stack_top() == '-')
				{
					while (stack_top() == '*' || stack_top() == '/' || stack_top() == '%'||stack_top() =='+'||stack_top()=='-')
					{
						a = stack_pop();
						printf("%c ", a);
					}
				}
				stack_push('+');

				break;
			case '-':
				if (stack_top() == '*' || stack_top() == '/' || stack_top() == '%' || stack_top() == '+' || stack_top() == '-')
				{
					while (stack_top() == '*' || stack_top() == '/' || stack_top() == '%' || stack_top() == '+' || stack_top() == '-')
					{
						a = stack_pop();
						printf("%c ", a);
					}
				}
				stack_push('-');
				break;
			case '*':
				if (stack_top() == '*' || stack_top() == '/' || stack_top() == '%' )
				{
					while (stack_top() == '*' || stack_top() == '/' || stack_top() == '%')
					{
						a = stack_pop();
						printf("%c ", a);
					}
				}
				stack_push('*');
				break;
			case '/':
				if (stack_top() == '*' || stack_top() == '/' || stack_top() == '%')
				{
					while (stack_top() == '*' || stack_top() == '/' || stack_top() == '%')
					{
						a = stack_pop();
						printf("%c ", a);
					}
				}
				stack_push('/');
				break;
			case '%':
				if (stack_top() == '*' || stack_top() == '/' || stack_top() == '%')
				{
					while (stack_top() == '*' || stack_top() == '/' || stack_top() == '%')
					{
						a = stack_pop();
						printf("%c ", a);
					}
				}
				stack_push('%');
				break;
			case '(':
				stack_push('(');
				break;
			case ')':
				while (1)
				{
					a = stack_pop();
					if (a == '(') {
						break;
					}
					else {
						printf("%c ", a);
					}
				}
				break;
			default:
				printf("%c ", input);
				break;
			}

		}

	}

	fclose(f);
	while (1) {
		if (stack_empty()==0) {
			a = stack_pop();
			if (a != '(')
				printf("%c ", a);
		}
		else
		{
			printf("\n");
			return 0;
		}
	}
}
