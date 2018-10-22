#include<stdio.h>
typedef int  DataType;

typedef struct  BSTreeNode{
	DataType data;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
} BSTreeNode;

BSTreeNode *CreateNode(int data)
{
	BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
//求第K层节点个数
int GetLevelkSize(BSTreeNode *root, int k)
{
	assert(k >= 1);
	if (root == NULL)
	{
		//空树，任意层都是0个
		return  0;
	}
	if (k == 1)
	{//第一层只有一个根节点
		return 1;
	}
	int left = GetLevelkSize(root->left, k - 1);
	int right = GetLevelkSize(root->right, k - 1);

	return  left + right;
}
//求树的高度
#define  MAX(a ,b)  ((a)>(b)? (a):(b))

int GetHeight(BSTreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	//当子树有一个节点的时候，可以写，也可以不写
	//写的话，节省两次函数调用
	return MAX(GetHeight(root->left), GetHeight(root->right)) + 1;
}
//查找元素
//前提是，树里面的data不重复
//如果找到了，就返回节点地址，否则就返回NULL；
//先匹配根，再左子树，再右子树
BSTreeNode *Find(BSTreeNode *root, DataType data)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == data)
	{
		return root;
	}
	BSTreeNode *result = Find(root->left, data);
	if (result != NULL)
	{
		return result;
	}
	result = Find(root->right, data);
	if (result != NULL)
	{
		return result;
	}
	else
	{
		return NULL;
	}
}