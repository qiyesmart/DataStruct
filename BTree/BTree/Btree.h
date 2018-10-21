#pragma once

//������
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
//ǰ�򴴽�������
BSTreeNode *CreateTree(int preOrder[], int size, int *pUsedSize);
//ǰ�����
void  PreOrder(BSTreeNode *root);
//ǰ�����
void  InOrder(BSTreeNode *root);
//�������
void PostOrder(BSTreeNode *root);
//�����Ľڵ�ĸ���
//������(���ú����������)
int  GetSize1(BSTreeNode *root);
//��Ҷ�ӽڵ����
int GeatLeafSize(BSTreeNode *root);