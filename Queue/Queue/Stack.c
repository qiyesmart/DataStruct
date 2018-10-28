#include "Stack.h"
#include<stdio.h>
#include<string.h>

void   test1()
{
	QueueS  qs;
	QSInit(&qs);
	for (int i = 0; i < 10; i++)
	{
		QSPush(&qs, i);
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", QSFront(&qs));
		QSPop(&qs);
	}
}
int main()
{
	test1();
	system("pause");
	return 0;
}