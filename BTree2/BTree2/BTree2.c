#include"BTree2.h"
#include"Queue.h"

BSTreeNode *CreateTree(int preOrder[], int size, int *pUsedSize)
{
	if (size <= 0)
	{
		*pUsedSize = 0;
		return NULL;
	}
	int leftUse, rightUse;
	int rootValue = preOrder[0];
	if (rootValue == -1)
	{
		*pUsedSize = 1;
		return NULL;
	}
	BSTreeNode *root = CreateNode(rootValue);
	root->left = CreateTree(preOrder + 1, size - 1, &leftUse);
	root->right = CreateTree(preOrder + 1 + leftUse, size - 1 - leftUse, &rightUse);

	//���ϴ󱨸�ʵ��ʹ�����
	*pUsedSize = 1 + leftUse + rightUse;
	return root;
}


void LevelOrder(BSTreeNode *root)//�������

{
	Queue  queue;
	QueueInit(&queue);
	BSTreeNode *front;
	if (root == NULL)
	{
		return ;
	}
	QueuePush(&queue, root);//�ŵ��ǽڵ�ĵ�ַ�����ǽڵ��data��
	while (!QueueEmpty(&queue))
	{
		front = QueueFront(&queue);
		QueuePop(&queue);
		//front��ȡ���ߣ��սڵ��ǲ�Ҫ��
		//�������
		if (front->left != NULL)
		{
			QueuePush(&queue, front->left);
		}
		if (front->right != NULL)
		{
			QueuePush(&queue, front->right);
		}
		//�������front �ڵ�
		printf("%d", front->data);
	}
}

//�ж�һ�����ǲ�����ȫ������
int IsCompleteTree(BSTreeNode *root)
{
	Queue  queue;
	QueueInit(&queue);
	BSTreeNode *front;
	if (root == NULL)
	{
		return 1;
	}
	QueuePush(&queue, root);
	while (!QueueEmpty(&queue))
	{
		//��������϶������ߵ�
		front = QueueFront(&queue);
		QueuePop(&queue);
		//����Ͳ��������ͬ��front�п�����NULL
		if (front == NULL)
		{
			//�������ȫ��������ʣ��Ľ��Ӧ��ȫ��NULL
			break;
		}
		QueuePush(&queue, front->left);
		QueuePush(&queue, front->right);
	}
	//����ʣ�����Ƿ���NULL
	while (!QueueEmpty(&queue))
	{
		front = QueueFront(&queue);
		QueuePop(&queue);
		if (front != NULL)
		{//TODO:����
			return 0;
		}
	}
	//TODO:����
	return 1;
}

#include "Stack.h"

//�ǵݹ�ǰ�����
void    PreOrderLoop(BSTreeNode *root)
{
	Stack  stack;
	StackInit(&stack);
	BSTreeNode *cur, *top;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack))
	{
		while (cur != NULL)
		{
			printf("%d", cur->data);
			StackPush(&stack, cur);
			cur = cur->left;
		}
		top = StackTop(&stack);
		StackPop(&stack);

		cur = top->right;
	}
}

//�ǵݹ��������
void    InOrderLoop(BSTreeNode *root)
{
	Stack  stack;
	StackInit(&stack);
	BSTreeNode *cur, *top;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack))
	{
		//����������
		while (cur != NULL)
		{
			StackPush(&stack, cur);
			cur = cur->left;
		}
		//top���������Ѿ�����
		top = StackTop(&stack);
		StackPop(&stack);
		printf("%d", top->data);
		//�����������˼�����top������
		cur = top->right;
	}
}

//�ǵݹ�������
void    PostOrderLoop(BSTreeNode *root)
{
	Stack  stack;
	StackInit(&stack);
	//lati��һ�����������Ľ��
	BSTreeNode *cur, *top,*last=NULL;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack))
	{
		//����������
		while (cur != NULL)
		{
			StackPush(&stack, cur);
			cur = cur->left;
		}
		//top���������Ѿ���������
		top = StackTop(&stack);
		if (top->right == NULL || top->right == last)
		{
			//�������������������
			StackPop(&stack);
			printf("%d", top->data);
			//��¼�������Ľ��
			last = top;
		}
		else
		{
			//���������û�б�����
			cur = top->right;
		}
	}
} 


//����
//�ݹ�
void  Mirror1(BSTreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	Mirror1(root->left);
	Mirror1(root->right);

	BSTreeNode *t = root->left;
	root->left = root->right;
	root->right = t;

}

//�ǵݹ�
void  Mirror2(BSTreeNode *root)
{
	Stack  stack;
	StackInit(&stack);
	//lati��һ�����������Ľ��
	BSTreeNode *cur, *top, *last = NULL;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack))
	{
		//����������
		while (cur != NULL)
		{
			StackPush(&stack, cur);
			cur = cur->left;
		}
		//top���������Ѿ���������
		top = StackTop(&stack);
		if (top->right == NULL || top->right == last)
		{
			//�������������������
			StackPop(&stack);
			BSTreeNode *t = root->left;
			root->left = root->right;
			root->right = t;
			//��¼�������Ľ��
			last = top;
		}
		else
		{
			//���������û�б�����
			cur = top->right;
		}
	}
}
void test()
{
	int preOrder[] = { 1, 2, 4, -1, -1, -1, 3 };
	int size = sizeof(preOrder) / sizeof(int);
	int usedSize;
	BSTreeNode *root = CreateTree(preOrder, size, &usedSize);
	/*Preorder(root); printf("\n");*/
	/*LevelOrder(root); printf("\n");
	int t=IsCompleteTree(root);
	printf("%d\n",t);*/
	PreOrderLoop(root); printf("\n");
	InOrderLoop(root); printf("\n");
	PostOrderLoop(root); printf("\n");
	Mirror2(root);
}

int main()
{
	test();
	system("pause");
	return 0;
}