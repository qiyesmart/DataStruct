
#include  "Btree.h"

//1.创建出树的根节点
//创建过程中，使用的字符个数
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
//前序遍历

void Preorder(BSTreeNode *root)
{
	// 终止条件
	if (root == NULL) {
		return;
	}

	// 根
	printf("%d ", root->data);
	// 左子树，子问题用递归处理
	Preorder(root->left);
	// 右子树，子问题用递归处理
	Preorder(root->right);
}

//中序遍历

void InOrder(BSTreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	InOrder(root->left);
	printf("%d", root->data);
	InOrder(root->right);
}
//后序遍历
void PostOrder(BSTreeNode *root)
{
	// 终止条件
	if (root == NULL) {
		return;
	}

	// 左子树，子问题用递归处理
	PostOrder(root->left);
	// 右子树，子问题用递归处理
	PostOrder(root->right);
	// 根
	printf("%d", root->data);
}
//求树的节点的个数
//遍历法(利用后序遍历计数)
int count = 0;
int  GetSize1(BSTreeNode *root)
{
		if (root == NULL) {
			return;
		}

		GetSize1(root->left);
		GetSize1(root->right);
		count++;
		return  count;
}
//求叶子节点个数
int GeatLeafSize(BSTreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	else{
		if (root->left == NULL&&root->right == NULL)
		{
			return 1;
		}
		else
		{
			return GeatLeafSize(root->left) +  GeatLeafSize(root->right);
		}
	}
}
void test()
{
	int preOrder[] = { 1, 2, 4, -1,-1,-1,3 };
	int size = sizeof(preOrder) / sizeof(int);
	int usedSize;
	BSTreeNode *root = CreateTree(preOrder, size, &usedSize);
	Preorder(root); printf("\n");
	InOrder(root); printf("\n");
	PostOrder(root); printf("\n");
	int t = GetSize1(root); printf("%d\n", t);
	printf("%d\n", GeatLeafSize(root));
	
	
}

int main()
{
	test();
	system("pause");
	return 0;
}