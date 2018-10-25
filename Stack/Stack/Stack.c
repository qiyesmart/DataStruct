#include "Stack.h"

//括号匹配问题
void  MatchBrackets(const  char *str)
{
	Stack stack;
	StackInit(&stack);

	const char *p = str;
	char left;
	while (*p != '\0')
	{
		switch (*p)
		{
		case '{':
		case '[':
		case '(':
			StackPush(&stack, *p);
			break;
		case '}':
		case ']':
		case ')':
			if (StackEmpty(&stack))
			{
				printf("右括号多\n");
				return;
			}
			left = StackTop(&stack);
			StackPop(&stack);
			if (!((left == '{'&&*p == '}')
				|| (left == '['&&*p == ']')
				|| (left == '('&&*p == ')')))
			{
				printf("左右括号不匹配\n");
				return;
			}
			break;
		default:
			break;
		}
		p++;
	}
	if (!StackEmpty(&stack))
	{
		printf("左括号多\n");
	}
	else
	{
		printf("匹配成功\n");
	}
}

//利用栈实现逆波兰表达式
void RPN(Item array[], int size)
{
	Stack  stack;
	StackInit(&stack);
	for (int i = 0; i < size; i++)
	{
		if (array[i].type == NUMBER)
		{
			StackPush(&stack, array[i].number);
		}
		else
		{
			int n1 = StackTop(&stack);
			StackPop(&stack);
			int n2 = StackTop(&stack);
			StackPop(&stack);
			int result;
			switch (array[i].operator)
			{
			case ADD:
				result = n1 + n2;
				break;
			case SUB:
				result = n2 - n1;
				break;
			case MUL:
				result = n1*n2;
				break;
			case DIV:
				result = n2 / n1;
			}
			StackPush(&stack, result);
		}
	}
	assert(StackSize(&stack) == 1);
	printf("%d\n", StackTop(&stack));
}

//
void test()
{
     int size = sizeof(array) / sizeof(array[0]);
     RPN(array,size);
	

}
int main()
{
	test();
	system("pause");
	return 0;
}
