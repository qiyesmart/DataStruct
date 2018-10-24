
//单链表实现约瑟夫环
ListNode * JosephCycle(ListNode *first, int k)
{
	//第一步，链表构成环
	ListNode *tail = first;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = first;
	//第二部
	ListNode *cur = first;
	//循环结束条件是链表中只剩一个结点
	while (cur->next != cur)
	{
		ListNode *prev = NULL;
		for (int i = 0; i < k - 1; i++)
		{
			prev = cur;
			cur = cur->next;
		}
		//cur就是要删除的结点
		prev->next = cur->next;
		free(cur);
		cur = prev->next;
	}
	cur->next = NULL;
	return cur;
}

//合并两个有序链表，合并后依然有序(升序）
ListNode *MergeOrderedList(ListNode *list1, ListNode *list2)
{
	ListNode *cur1 = list1;
	ListNode *cur2 = list2;
	ListNode *result = NULL;//结果链表
	ListNode *tail = NULL;//结果链表中的最后一个结点，方便尾插
	ListNode *next;//保存遍历过程中的下一个结点
	while (cur1 != NULL&&cur2 != NULL)
	{
		if (cur1->data <= cur2->data)
		{
			if (result != NULL)
			{
				//结果链表不为空，直接在最后一个结点上做插入
				//保存链表1的下一个结点，让循环继续
				next = cur1->next;
				//插入过程
				tail->next = cur1;
				cur1->next = NULL;
				//保存新的最后一个结点
				tail = cur1;
				cur1 = next;
			}
			else
			{
				//保存链表1的下一个结点，让循环继续
				next = cur1->next;
				result = cur1;
				cur1->next = NULL;
				//保存新的最后一个结点
				tail = cur1;
				cur1 = next;
			}
		}
		else
		{
			if (result != NULL)
			{
				//结果链表不为空，直接在最后一个结点上做插入
				//保存链表1的下一个结点，让循环继续
				next = cur2->next;
				//插入过程
				tail->next = cur2;
				cur2->next = NULL;
				//保存新的最后一个结点
				tail = cur2;
				cur2 = next;
			}
			else
			{
				//保存链表1的下一个结点，让循环继续
				next = cur2->next;
				result = cur2;
				cur2->next = NULL;
				//保存新的最后一个结点
				tail = cur2;
				cur2 = next;
			}
		}
	}
	//一个链表为空了
	if (cur1 == NULL)
	{
		tail->next = cur2;
	}
	if (cur2 == NULL)
	{
		tail->next = cur1;
	}
	return result;
}

//求两个已经排序单链表中相同的数据
void   PrintInsertsection(ListNode *list1, ListNode *list2)
{
	ListNode *cur1 = list1;
	ListNode *cur2 = list2;
	while (cur1 != NULL&&cur2 != NULL)
	{
		if (cur1->data < cur2->data)
		{
			cur1 = cur1->next;
		}
		else if (cur1->data > cur2->data)
		{
			cur2 = cur2->next;
		}
		else
		{
			printf("%d ", cur1->data);
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
	}
}
//改进:如果打印的数据相同，直接过滤掉
void   PrintInsertsectionSame(ListNode *list1, ListNode *list2)
{
	ListNode *cur1 = list1;
	ListNode *cur2 = list2;
	DataType  data;
	while (cur1 != NULL&&cur2 != NULL)
	{
		if (cur1->data < cur2->data)
		{
			cur1 = cur1->next;
		}
		else if (cur1->data > cur2->data)
		{
			cur2 = cur2->next;
		}
		else
		{
			printf("%d ", cur1->data);
			data = cur1->data;
			while (cur1 != NULL&&cur1->data == data)
			{
				cur1 = cur1->next;
			}
			while (cur2 != NULL&&cur2->data == data)
			{
				cur2 = cur2->next;
			}
		}
	}
}

//查找单链表中间结点，只能遍历一次链表
void    FindMid(ListNode *first)
{
	ListNode *fast = first;
	ListNode *slow = first;
	while (1)
	{
		fast = fast->next;
		if (fast == NULL)
		{
			break;
		}
		fast = fast->next;
		if (fast == NULL)
		{
			break;
		}
		slow = slow->next;
	}
	printf("%d", slow->data);

}

//删除倒数第K个结点
void FindTailK(ListNode *first, int k)
{
	ListNode *forward = first;
	ListNode *backward = first;

	while (k--)
	{
		forward = forward->next;
	}
	while (forward != NULL)
	{
		forward = forward->next;
		backward = backward->next;

	}

	printf("%d", backward->data);
}

//删除一个无头单链表的非尾结点（不能遍历）
void   RemoveNoFirst(ListNode *pos)
{
	pos->data = pos->next->data;
	ListNode *del = pos->next;
	pos->next = pos->next->next;
	free(del);
}
//在一个无头单链表的非尾结点前插入结点（不能遍历）
void InsertNoFirst(ListNode *pos, DataType data)
{
	ListNode *newNode = CreateNode(data);
	newNode->data = pos->data;
	newNode->next = pos->next;
	pos->data = data;
	pos->next = newNode;
}

//复杂链表的复制。一个链表的每个节点，有一个指向next指针指向下一个节点，
//还有一个random指针指向这个链表中的一个随机节点或者NULL，
//现在要求实现复制这个链表，返回复制后的新链表
typedef struct ComplexNode {
	int data;
	struct ComplexNode *next;
	struct ComplexNode *random;
}	CN;

CN * CreateNode1(int data)
{
	CN *node = (CN *)malloc(sizeof(CN));
	node->data = data;
	node->random = node->next = NULL;

	return node;
}

CN * CNInit()
{
	CN *n1 = CreateNode1(1);
	CN *n2 = CreateNode1(2);
	CN *n3 = CreateNode1(3);
	CN *n4 = CreateNode1(4);

	n1->next = n2; n2->next = n3; n3->next = n4;
	n1->random = n3; n2->random = n1; n3->random = n3;

	return n1;
}
void  Copy(CN *list)
{
	// 复制链表每个结点，让新的结点跟在老的结点后边
	CN *cur = list;
	CN *newNode;
	// cur 只遍历老的结点
	while (cur != NULL) {
		newNode = CreateNode(cur->data);
		newNode->next = cur->next;
		cur->next = newNode;

		cur = newNode->next;
	}

	// 复制 random 字段
	cur = list;
	while (cur != NULL) {
		newNode = cur->next;
		if (cur->random != NULL) {
			newNode->random = cur->random->next;
		}

		cur = cur->next->next;
	}

	cur = list;
	CN *next, *newNext;
	CN *result = list->next;
	while (cur != NULL) {
		newNode = cur->next;
		next = newNode->next;
		if (next == NULL) {
			newNext = NULL;
		}
		else {
			newNext = next->next;
		}

		cur->next = next;
		newNode->next = newNext;

		cur = next;
	}

	printf("复制成功\n");
}