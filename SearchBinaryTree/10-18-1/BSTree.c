#include"BSTree.h"

//����
//�ݹ���ʽ
int BSTreeFind1(BSTreeNode *root, DataType key)
{
	if (root == NULL) {
		// ����
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
//�ǵݹ�
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
//����
//�ǵݹ�
int  BSTreeInsert1(BSTreeNode **root, DataType key)
{
	BSTreeNode *cur = *root;
	BSTreeNode *parent = NULL;
	//���ҹ���
	while (cur != NULL)
	{
		if (key == cur->key)
		{//�ظ�����ʧ��
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
	//�������
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
//����ݹ�
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
		//�����������ԣ��ı��ֻ��ջ����ʱ������ֵ
		//BSTreeNode *child=(*root)-left;
		//return BSTreeInsert2(&child,key);
		return BSTreeInsert2(&(*root)->left, key);
	}
	else
	{
		return BSTreeInsert2(&(*root)->right, key);
	}
}

//ɾ��
//�ǵݹ�
//�ҵ���ɾ�����ɹ�����1�����򷵻�0
static void RemoveLeftNULL(BSTreeNode *parent, BSTreeNode **root, BSTreeNode *cur, DataType key)
{
	if (parent == NULL)
	{//ɾ�����ڵ�
		*root = cur->right;
	}
	else
	{
		if (key < parent->key)
		{
			//cur��parent��left
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
	{//ɾ�����ڵ�
		*root = cur->left;
	}
	else
	{
		if (key < parent->key)
		{
			//cur��parent��left
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
	//��������������
	BSTreeNode *del = cur->left;
	BSTreeNode *delParent = NULL;
	while (del->right != NULL)
	{
		delParent = del;
		del = del->right;
	}
	//del����������������
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
	//�Ȳ��ң���ɾ��
	BSTreeNode *cur = *root;
	BSTreeNode *parent = NULL;
	while (cur != NULL)
	{
		if (key == cur->key)
		{
			//����ɾ��
			if (cur->left == NULL)
			{
				//��ǰcurû������
				RemoveLeftNULL(parent, root, cur,key);
			}
			else if (cur->right == NULL)
			{
				//��ǰcurû���Һ���
				RemoveRightNULL(parent, root, cur,key);
			}
			else
			{
				//������������Ϊ��
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
//�ݹ�ɾ��
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
			//���Ҷ���Ϊ��
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

//����
void test()
{
	int r;
	BSTreeNode *root = NULL;
	r = BSTreeInsert2(&root, 5); printf("����%s\n", r ? "�ɹ�" : "���ɹ�");
	r = BSTreeInsert2(&root, 3); printf("����%s\n", r ? "�ɹ�" : "���ɹ�");
	r = BSTreeInsert2(&root, 7); printf("����%s\n", r ? "�ɹ�" : "���ɹ�");
	r = BSTreeInsert2(&root, 1); printf("����%s\n", r ? "�ɹ�" : "���ɹ�");
	r = BSTreeInsert2(&root, 4); printf("����%s\n", r ? "�ɹ�" : "���ɹ�");
	r = BSTreeInsert2(&root, 6); printf("����%s\n", r ? "�ɹ�" : "���ɹ�");
	r = BSTreeInsert2(&root, 8); printf("����%s\n", r ? "�ɹ�" : "���ɹ�");
	r = BSTreeInsert2(&root, 0); printf("����%s\n", r ? "�ɹ�" : "���ɹ�");
	r = BSTreeInsert2(&root, 2); printf("����%s\n", r ? "�ɹ�" : "���ɹ�");
	r = BSTreeInsert2(&root, 9); printf("����%s\n", r ? "�ɹ�" : "���ɹ�");

	
	
	/*r = BSTreeFind1(root, 6); printf("����6%s/n", r ? "�ɹ�" : "���ɹ�");
	r = BSTreeFind2(root, 1); printf("����1%s/n", r ? "�ɹ�" : "���ɹ�");*/

	BSTreeNodeRemove2(&root, 2);
}
	int main()
{
   test();
   system("pause");
   return 0;
}
	