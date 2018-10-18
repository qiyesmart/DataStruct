#pragma once

#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct BSTreeNode{
	DataType  key;
	struct BSTreeNode  *left;
	struct BSTreeNode  *right;
}BSTreeNode;
//µÝ¹é
int BSTreeFind1(BSTreeNode *root, DataType key);
//·ÇµÝ¹é
int BSTreeFind2(BSTreeNode *root, DataType key);
//²åÈë
//·ÇµÝ¹é
int  BSTreeInsert1(BSTreeNode **root, DataType key);
//µÝ¹é
int BSTreeInsert2(BSTreeNode **root, DataType key);
//É¾³ý
//·ÇµÝ¹é
int BSTreeNodeRemove1(BSTreeNode **root, DataType key);
//µÝ¹é
int BSTreeNodeRemove2(BSTreeNode **root, DataType key);
