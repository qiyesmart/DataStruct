
#include  "Btree.h"

//1.���������ĸ��ڵ�
//���������У�ʹ�õ��ַ�����
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
//ǰ�����

void Preorder(BSTreeNode *root)
{
	// ��ֹ����
	if (root == NULL) {
		return;
	}

	// ��
	printf("%d ", root->data);
	// ���������������õݹ鴦��
	Preorder(root->left);
	// ���������������õݹ鴦��
	Preorder(root->right);
}

//�������

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
//�������
void PostOrder(BSTreeNode *root)
{
	// ��ֹ����
	if (root == NULL) {
		return;
	}

	// ���������������õݹ鴦��
	PostOrder(root->left);
	// ���������������õݹ鴦��
	PostOrder(root->right);
	// ��
	printf("%d", root->data);
}
//�����Ľڵ�ĸ���
//������(���ú����������)
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
//��Ҷ�ӽڵ����
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