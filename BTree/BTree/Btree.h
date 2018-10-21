#pragma once

//二叉树
#include<stdio.h>
#include<stdlib.h>

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
//前序创建二叉树
BSTreeNode *CreateTree(int preOrder[], int size, int *pUsedSize);
//前序遍历
void  PreOrder(BSTreeNode *root);
//前序遍历
void  InOrder(BSTreeNode *root);
//后序遍历
void PostOrder(BSTreeNode *root);
//求树的节点的个数
//遍历法(利用后序遍历计数)
int  GetSize1(BSTreeNode *root);
//求叶子节点个数
int GeatLeafSize(BSTreeNode *root);