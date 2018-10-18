#pragma once

#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct BSTreeNode{
	DataType  key;
	struct BSTreeNode  *left;
	struct BSTreeNode  *right;
}BSTreeNode;
//�ݹ�
int BSTreeFind1(BSTreeNode *root, DataType key);
//�ǵݹ�
int BSTreeFind2(BSTreeNode *root, DataType key);
//����
//�ǵݹ�
int  BSTreeInsert1(BSTreeNode **root, DataType key);
//�ݹ�
int BSTreeInsert2(BSTreeNode **root, DataType key);
//ɾ��
//�ǵݹ�
int BSTreeNodeRemove1(BSTreeNode **root, DataType key);
//�ݹ�
int BSTreeNodeRemove2(BSTreeNode **root, DataType key);
