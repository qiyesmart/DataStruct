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

	//向老大报告实际使用情况
	*pUsedSize = 1 + leftUse + rightUse;
	return root;
}


void LevelOrder(BSTreeNode *root)//层序遍历

{
	Queue  queue;
	QueueInit(&queue);
	BSTreeNode *front;
	if (root == NULL)
	{
		return ;
	}
	QueuePush(&queue, root);//放的是节点的地址，不是节点的data；
	while (!QueueEmpty(&queue))
	{
		front = QueueFront(&queue);
		QueuePop(&queue);
		//front拉取下线，空节点是不要的
		//先左后右
		if (front->left != NULL)
		{
			QueuePush(&queue, front->left);
		}
		if (front->right != NULL)
		{
			QueuePush(&queue, front->right);
		}
		//层序遍历front 节点
		printf("%d", front->data);
	}
}

//判断一棵树是不是完全二叉树
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
		//这个条件肯定不会走到
		front = QueueFront(&queue);
		QueuePop(&queue);
		//这里和层序遍历不同，front有可能是NULL
		if (front == NULL)
		{
			//如果是完全二叉树，剩余的结点应该全是NULL
			break;
		}
		QueuePush(&queue, front->left);
		QueuePush(&queue, front->right);
	}
	//队列剩余结点是否都是NULL
	while (!QueueEmpty(&queue))
	{
		front = QueueFront(&queue);
		QueuePop(&queue);
		if (front != NULL)
		{//TODO:销毁
			return 0;
		}
	}
	//TODO:销毁
	return 1;
}

#include "Stack.h"

//非递归前序遍历
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

//非递归中序遍历
void    InOrderLoop(BSTreeNode *root)
{
	Stack  stack;
	StackInit(&stack);
	BSTreeNode *cur, *top;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack))
	{
		//遍历左子树
		while (cur != NULL)
		{
			StackPush(&stack, cur);
			cur = cur->left;
		}
		//top的左子树已经遍历
		top = StackTop(&stack);
		StackPop(&stack);
		printf("%d", top->data);
		//利用子问题的思想遍历top右子树
		cur = top->right;
	}
}

//非递归后序遍历
void    PostOrderLoop(BSTreeNode *root)
{
	Stack  stack;
	StackInit(&stack);
	//lati上一个被遍历过的结点
	BSTreeNode *cur, *top,*last=NULL;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack))
	{
		//遍历左子树
		while (cur != NULL)
		{
			StackPush(&stack, cur);
			cur = cur->left;
		}
		//top的左子树已经遍历过了
		top = StackTop(&stack);
		if (top->right == NULL || top->right == last)
		{
			//如果右子树被遍历过了
			StackPop(&stack);
			printf("%d", top->data);
			//记录被遍历的结点
			last = top;
		}
		else
		{
			//如果右子树没有被遍历
			cur = top->right;
		}
	}
} 


//求镜像
//递归
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

//非递归
void  Mirror2(BSTreeNode *root)
{
	Stack  stack;
	StackInit(&stack);
	//lati上一个被遍历过的结点
	BSTreeNode *cur, *top, *last = NULL;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack))
	{
		//遍历左子树
		while (cur != NULL)
		{
			StackPush(&stack, cur);
			cur = cur->left;
		}
		//top的左子树已经遍历过了
		top = StackTop(&stack);
		if (top->right == NULL || top->right == last)
		{
			//如果右子树被遍历过了
			StackPop(&stack);
			BSTreeNode *t = root->left;
			root->left = root->right;
			root->right = t;
			//记录被遍历的结点
			last = top;
		}
		else
		{
			//如果右子树没有被遍历
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