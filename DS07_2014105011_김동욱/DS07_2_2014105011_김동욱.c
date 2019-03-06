#include <stdio.h>
typedef struct Stack {
	char data[100];
	int ptr;
}Stack;
Stack stack;
void stack_push(int num);
int stack_pop();
int main() {
	FILE *f2;
	char input;
	int a, b;
	f2 = fopen("input.txt", "r");
	stack.ptr = -1;
	while (!feof(f2)) {
		fscanf(f2, "%c ", &input);
		//fflush();
		if (input == ' ')
			continue;
		if (input >= '0'&&input <= '9')
		{
			stack_push(input - '0');
		}
		else {
			switch (input) {
			case '+':
				b = stack_pop();
				a = stack_pop();
				stack_push(a + b);
				break;
			case '-':
				b = stack_pop();
				a = stack_pop();
				stack_push(a - b);
				break;
			case '*':
				b = stack_pop();
				a = stack_pop();
				stack_push(a * b);
				break;
			case '/':
				b = stack_pop();
				a = stack_pop();
				stack_push(a / b);
				break;
			case '%':
				b = stack_pop();
				a = stack_pop();
				stack_push(a % b);
				break;
			case '(':
				printf("(?");
				exit(1);
				break;
			case ')':
				printf(")?");
				break;
			default:
				break;
			}

		}

	}
	printf("%d\n", stack_pop());
	fclose(f2);
}

void stack_push(int num) {
	stack.data[++stack.ptr] = num;
}
int stack_pop() {
	return stack.data[stack.ptr--];
}