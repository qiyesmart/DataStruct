#include   "List.h"

static ListNode *CreateNode(DataType  data)
{
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//头插
void   ListPushFront(ListNode **ppfirst, DataType data)
{
	assert(ppfirst != NULL);
	//正常情况
	//指针ppfirst指向头结点，从堆上申请空间
	ListNode *newNode = CreateNode(data);
	newNode->next = *ppfirst;

	*ppfirst = newNode;
}

//尾插
void    ListPushBack(ListNode **ppfirst, DataType data)
{
	ListNode *newNode = CreateNode(data);
	//特殊情况，找到倒数第一个（至少有一个，特殊情况是链表为空）
	if (*ppfirst == NULL)
	{
		*ppfirst = newNode;
		return;
	}
	//通常情况
	ListNode *cur = *ppfirst;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newNode;
}

//头删
void   ListPopFront(ListNode **ppfirst)
{
	assert(ppfirst != NULL);//变量地址不为NULL
	assert(*ppfirst != NULL);//不能是空链表

	ListNode *del = *ppfirst;
	*ppfirst = del->next;

	//重点
	free(del);
}

//尾删
void  ListPopBack(ListNode **ppfirst)
{
	assert(ppfirst != NULL);//变量地址不为NULL
	assert(*ppfirst != NULL);//不能是空链表
	//链表中只有一个结点
	if ((*ppfirst)->next == NULL)
	{
		free(*ppfirst);
		*ppfirst = NULL;
		return;
	}
	//正常情况
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

//查找
ListNode   *ListFind(ListNode *first, DataType data)
{
	for (ListNode *cur = first; cur != NULL; cur = cur->next)
	{
		if (data == cur->data)
			return cur;
	}
	return NULL;
}

//在结点前做插入（结点pos肯定在链表中&&pos不是空）
void   ListInsert(ListNode **ppfirst, ListNode *pos, DataType data)
{
	//头插
	if (*ppfirst==pos)
	{
		ListPushFront(ppfirst, data);
		return;
	}
	ListNode *cur = *ppfirst;
	//找到pos前一个结点
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	//插入新结点
	ListNode *newNode = CreateNode(data);
	newNode->next = cur-> next;
	cur->next = newNode;

}
	
//删除指定结点（结点pos肯定在链表中&&pos不是空）
void  ListErase(ListNode **ppfirst, ListNode *pos)
{
	//头删
	if (*ppfirst == pos)
	{
		ListPopFront(ppfirst);
		return;
	}
	ListNode *cur = *ppfirst;
	//找到pos前一个结点
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);
}

//逆向打印一个链表
//方法一
void PrintReverse(ListNode *first)
{
	ListNode *end = NULL;//要打印的后一个结点
	while (end != first)
	{
		ListNode *cur = first;
		//找到要打印的结点
		while (cur->next != end)
		{
			cur = cur->next;
		}
		//要打印的节点
		printf("%d", cur->data);
		end = cur;
	}
}
//方法二（递归求解）
void PrintReserveRecursion(ListNode *first)
{
	if (first->next == NULL)
	{
		printf("%d", first->data);
	}
	else
	{
		PrintReserveRecursion(first->next);
		//链表中，除了first外的所有结点都已经逆序打印
		printf("%d", first->data);
	}
}

//逆序/反转单链表
//返回逆置后的链表第一个结点地址
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
		ListNode *cur = first;	// 一直指向原来链表的第一个结点
		ListNode *node;
		while (cur != NULL) {
			// 从原链表头删
			node = cur;
			cur = cur->next;

			// 头插到结果链表
			node->next = result;
			result = node;
		}

		// 逆置完，做个打印
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