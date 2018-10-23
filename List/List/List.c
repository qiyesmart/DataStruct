#include   "List.h"

static ListNode *CreateNode(DataType  data)
{
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//ͷ��
void   ListPushFront(ListNode **ppfirst, DataType data)
{
	assert(ppfirst != NULL);
	//�������
	//ָ��ppfirstָ��ͷ��㣬�Ӷ�������ռ�
	ListNode *newNode = CreateNode(data);
	newNode->next = *ppfirst;

	*ppfirst = newNode;
}

//β��
void    ListPushBack(ListNode **ppfirst, DataType data)
{
	ListNode *newNode = CreateNode(data);
	//����������ҵ�������һ����������һ�����������������Ϊ�գ�
	if (*ppfirst == NULL)
	{
		*ppfirst = newNode;
		return;
	}
	//ͨ�����
	ListNode *cur = *ppfirst;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newNode;
}

//ͷɾ
void   ListPopFront(ListNode **ppfirst)
{
	assert(ppfirst != NULL);//������ַ��ΪNULL
	assert(*ppfirst != NULL);//�����ǿ�����

	ListNode *del = *ppfirst;
	*ppfirst = del->next;

	//�ص�
	free(del);
}

//βɾ
void  ListPopBack(ListNode **ppfirst)
{
	assert(ppfirst != NULL);//������ַ��ΪNULL
	assert(*ppfirst != NULL);//�����ǿ�����
	//������ֻ��һ�����
	if ((*ppfirst)->next == NULL)
	{
		free(*ppfirst);
		*ppfirst = NULL;
		return;
	}
	//�������
	ListNode  *del;
	ListNode  *cur = *ppfirst;

	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	del = cur->next;
	cur->next = NULL;
	free(del);
}

//����
ListNode   *ListFind(ListNode *first, DataType data)
{
	for (ListNode *cur = first; cur != NULL; cur = cur->next)
	{
		if (data == cur->data)
			return cur;
	}
	return NULL;
}

//�ڽ��ǰ�����루���pos�϶���������&&pos���ǿգ�
void   ListInsert(ListNode **ppfirst, ListNode *pos, DataType data)
{
	//ͷ��
	if (*ppfirst==pos)
	{
		ListPushFront(ppfirst, data);
		return;
	}
	ListNode *cur = *ppfirst;
	//�ҵ�posǰһ�����
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	//�����½��
	ListNode *newNode = CreateNode(data);
	newNode->next = cur-> next;
	cur->next = newNode;

}
	
//ɾ��ָ����㣨���pos�϶���������&&pos���ǿգ�
void  ListErase(ListNode **ppfirst, ListNode *pos)
{
	//ͷɾ
	if (*ppfirst == pos)
	{
		ListPopFront(ppfirst);
		return;
	}
	ListNode *cur = *ppfirst;
	//�ҵ�posǰһ�����
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);
}

//�����ӡһ������
//����һ
void PrintReverse(ListNode *first)
{
	ListNode *end = NULL;//Ҫ��ӡ�ĺ�һ�����
	while (end != first)
	{
		ListNode *cur = first;
		//�ҵ�Ҫ��ӡ�Ľ��
		while (cur->next != end)
		{
			cur = cur->next;
		}
		//Ҫ��ӡ�Ľڵ�
		printf("%d", cur->data);
		end = cur;
	}
}
//���������ݹ���⣩
void PrintReserveRecursion(ListNode *first)
{
	if (first->next == NULL)
	{
		printf("%d", first->data);
	}
	else
	{
		PrintReserveRecursion(first->next);
		//�����У�����first������н�㶼�Ѿ������ӡ
		printf("%d", first->data);
	}
}

//����/��ת������
//�������ú�������һ������ַ
void ListPrint(ListNode *first)
{
	for (ListNode *cur = first; cur != NULL; cur = cur->next) {
		printf("%d ", cur->data);
	}
	printf("\n");
}
void  ReserseList(ListNode *first)
{
		ListNode *result = NULL;
		ListNode *cur = first;	// һֱָ��ԭ������ĵ�һ�����
		ListNode *node;
		while (cur != NULL) {
			// ��ԭ����ͷɾ
			node = cur;
			cur = cur->next;

			// ͷ�嵽�������
			node->next = result;
			result = node;
		}

		// �����꣬������ӡ
		ListPrint(result);
}

void test()
{
	ListNode *first;
	ListInit(&first);

	ListPushBack(&first, 1);
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);
	ListPushBack(&first, 4);
	ListPushBack(&first, 5);
	
	/*ListPopFront(&first);
	ListPopBack(&first);
	ListNode *result=ListFind(first, 3);
	ListInsert(&first, result, 8);
	ListErase(&first, result);*/
	/*PrintReverse(first);
	PrintReserveRecursion(first);*/
	ReserseList(first);
}
int main()
{
	test();
	system("pause");
	return 0;
}