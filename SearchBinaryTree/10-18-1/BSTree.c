#include"BSTree.h"

//查找
//递归形式
int BSTreeFind1(BSTreeNode *root, DataType key)
{
	if (root == NULL) {
		// 空树
		return 0;
	}

	if (key == root->key) {
		return 1;
	}
	else if (key < root->key) {
		return BSTreeFind1(root->left, key);
	}
	else {
		return BSTreeFind1(root->right, key);
	}
}
//非递归
int BSTreeFind2(BSTreeNode *root, DataType key)
{
	BSTreeNode *cur = root;
	while (cur != NULL)
	{
		if (key == cur->key)
		{
			return 1;
		}
		else if (key > cur->key)
		{
			cur = cur->right;
		}
		else
		{
			cur = cur->left;
		}

	}
	return 0;
}
//插入
//非递归
int  BSTreeInsert1(BSTreeNode **root, DataType key)
{
	BSTreeNode *cur = *root;
	BSTreeNode *parent = NULL;
	//查找过程
	while (cur != NULL)
	{
		if (key == cur->key)
		{//重复插入失败
			return 0;
		}
		parent = cur;
		 if (key > cur->key)
		{
			cur = cur->right;
		}
		else
		{
			cur = cur->left;
		}
	}
	BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	//插入过程
	if (parent == NULL)
	{
		*root = node;
		return 1;
	}
	if (key < parent->key)
	{
		parent->left = node;
	}
	else
	{
		parent->right = node;
	}
}
//插入递归
int BSTreeInsert2(BSTreeNode **root, DataType key)
{
	if (*root == NULL)
	{
		BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		*root = node;
		return 1;
	}
	if (key == (*root)->key)
	{
		return 0;
	}
	else if (key < (*root)->key)
	{
		//这种做法不对，改变的只是栈上临时变量的值
		//BSTreeNode *child=(*root)-left;
		//return BSTreeInsert2(&child,key);
		return BSTreeInsert2(&(*root)->left, key);
	}
	else
	{
		return BSTreeInsert2(&(*root)->right, key);
	}
}

//删除
//非递归
//找到就删除，成功返回1，否则返回0
static void RemoveLeftNULL(BSTreeNode *parent, BSTreeNode **root, BSTreeNode *cur, DataType key)
{
	if (parent == NULL)
	{//删除根节点
		*root = cur->right;
	}
	else
	{
		if (key < parent->key)
		{
			//cur是parent的left
			parent->left = cur->right;
		}
		else
		{
			parent->right = cur->right;
		}
	 }
	free(cur);
}
static void RemoveRightNULL(BSTreeNode *parent, BSTreeNode **root, BSTreeNode *cur, DataType key)
{
	if (parent == NULL)
	{//删除根节点
		*root = cur->left;
	}
	else
	{
		if (key < parent->key)
		{
			//cur是parent的left
			parent->left = cur->left;
		}
		else
		{
			parent->right = cur->left;
		}
	}
	free(cur);
}
static void RemeMoveHasLeftAndRight(BSTreeNode *cur)
{
	//找左子树中最大的
	BSTreeNode *del = cur->left;
	BSTreeNode *delParent = NULL;
	while (del->right != NULL)
	{
		delParent = del;
		del = del->right;
	}
	//del就是左子树中最大的
	cur->key = del->key;
	if (delParent == NULL)
	{
		cur->left = del->left;
	}
	else
	{
		delParent->right = del->left;
	}
	free(del);
}
int BSTreeNodeRemove1(BSTreeNode **root, DataType key)
{
	//先查找，后删除
	BSTreeNode *cur = *root;
	BSTreeNode *parent = NULL;
	while (cur != NULL)
	{
		if (key == cur->key)
		{
			//这里删除
			if (cur->left == NULL)
			{
				//当前cur没有左孩子
				RemoveLeftNULL(parent, root, cur,key);
			}
			else if (cur->right == NULL)
			{
				//当前cur没有右孩子
				RemoveRightNULL(parent, root, cur,key);
			}
			else
			{
				//左右子树都不为空
				RemeMoveHasLeftAndRight(cur);
			}
			return 0;
		}
		parent = cur;
		if (key < cur->key)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}
	return 0;
}
//递归删除
int BSTreeNodeRemove2(BSTreeNode **root, DataType key)
{
	if (*root == NULL);
	{
		return 0;
	}
	if (key == (*root)->key)
	{
		BSTreeNode *del = *root;
		if ((*root)->left = NULL)
		{
			*root = (*root)->right;
			free(del);
		}
		else if ((*root)->right = NULL)
		{
			*root = (*root)->left;
			free(del);
		}
		else
		{
			//左右都不为空
			RemeMoveHasLeftAndRight(*root);

		}
		return 1;
	}
	if (key < (*root)->key)
	{
		return BSTreeNodeRemove2(&(*root)->left, key);
	}
	else
	{
		return BSTreeNodeRemove2(&(*root)->right, key);
	}
}

//测试
void test()
{
	int r;
	BSTreeNode *root = NULL;
	r = BSTreeInsert2(&root, 5); printf("插入%s\n", r ? "成功" : "不成功");
	r = BSTreeInsert2(&root, 3); printf("插入%s\n", r ? "成功" : "不成功");
	r = BSTreeInsert2(&root, 7); printf("插入%s\n", r ? "成功" : "不成功");
	r = BSTreeInsert2(&root, 1); printf("插入%s\n", r ? "成功" : "不成功");
	r = BSTreeInsert2(&root, 4); printf("插入%s\n", r ? "成功" : "不成功");
	r = BSTreeInsert2(&root, 6); printf("插入%s\n", r ? "成功" : "不成功");
	r = BSTreeInsert2(&root, 8); printf("插入%s\n", r ? "成功" : "不成功");
	r = BSTreeInsert2(&root, 0); printf("插入%s\n", r ? "成功" : "不成功");
	r = BSTreeInsert2(&root, 2); printf("插入%s\n", r ? "成功" : "不成功");
	r = BSTreeInsert2(&root, 9); printf("插入%s\n", r ? "成功" : "不成功");

	
	
	/*r = BSTreeFind1(root, 6); printf("查找6%s/n", r ? "成功" : "不成功");
	r = BSTreeFind2(root, 1); printf("查找1%s/n", r ? "成功" : "不成功");*/

	BSTreeNodeRemove2(&root, 2);
}
	int main()
{
   test();
   system("pause");
   return 0;
}
	