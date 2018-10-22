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
//���K��ڵ����
int GetLevelkSize(BSTreeNode *root, int k)
{
	assert(k >= 1);
	if (root == NULL)
	{
		//����������㶼��0��
		return  0;
	}
	if (k == 1)
	{//��һ��ֻ��һ�����ڵ�
		return 1;
	}
	int left = GetLevelkSize(root->left, k - 1);
	int right = GetLevelkSize(root->right, k - 1);

	return  left + right;
}
//�����ĸ߶�
#define  MAX(a ,b)  ((a)>(b)? (a):(b))

int GetHeight(BSTreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	//��������һ���ڵ��ʱ�򣬿���д��Ҳ���Բ�д
	//д�Ļ�����ʡ���κ�������
	return MAX(GetHeight(root->left), GetHeight(root->right)) + 1;
}
//����Ԫ��
//ǰ���ǣ��������data���ظ�
//����ҵ��ˣ��ͷ��ؽڵ��ַ������ͷ���NULL��
//��ƥ�����������������������
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