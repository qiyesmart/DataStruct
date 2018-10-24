
//������ʵ��Լɪ��
ListNode * JosephCycle(ListNode *first, int k)
{
	//��һ���������ɻ�
	ListNode *tail = first;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = first;
	//�ڶ���
	ListNode *cur = first;
	//ѭ������������������ֻʣһ�����
	while (cur->next != cur)
	{
		ListNode *prev = NULL;
		for (int i = 0; i < k - 1; i++)
		{
			prev = cur;
			cur = cur->next;
		}
		//cur����Ҫɾ���Ľ��
		prev->next = cur->next;
		free(cur);
		cur = prev->next;
	}
	cur->next = NULL;
	return cur;
}

//�ϲ��������������ϲ�����Ȼ����(����
ListNode *MergeOrderedList(ListNode *list1, ListNode *list2)
{
	ListNode *cur1 = list1;
	ListNode *cur2 = list2;
	ListNode *result = NULL;//�������
	ListNode *tail = NULL;//��������е����һ����㣬����β��
	ListNode *next;//������������е���һ�����
	while (cur1 != NULL&&cur2 != NULL)
	{
		if (cur1->data <= cur2->data)
		{
			if (result != NULL)
			{
				//�������Ϊ�գ�ֱ�������һ�������������
				//��������1����һ����㣬��ѭ������
				next = cur1->next;
				//�������
				tail->next = cur1;
				cur1->next = NULL;
				//�����µ����һ�����
				tail = cur1;
				cur1 = next;
			}
			else
			{
				//��������1����һ����㣬��ѭ������
				next = cur1->next;
				result = cur1;
				cur1->next = NULL;
				//�����µ����һ�����
				tail = cur1;
				cur1 = next;
			}
		}
		else
		{
			if (result != NULL)
			{
				//�������Ϊ�գ�ֱ�������һ�������������
				//��������1����һ����㣬��ѭ������
				next = cur2->next;
				//�������
				tail->next = cur2;
				cur2->next = NULL;
				//�����µ����һ�����
				tail = cur2;
				cur2 = next;
			}
			else
			{
				//��������1����һ����㣬��ѭ������
				next = cur2->next;
				result = cur2;
				cur2->next = NULL;
				//�����µ����һ�����
				tail = cur2;
				cur2 = next;
			}
		}
	}
	//һ������Ϊ����
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

//�������Ѿ�������������ͬ������
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
//�Ľ�:�����ӡ��������ͬ��ֱ�ӹ��˵�
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

//���ҵ������м��㣬ֻ�ܱ���һ������
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

//ɾ��������K�����
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

//ɾ��һ����ͷ������ķ�β��㣨���ܱ�����
void   RemoveNoFirst(ListNode *pos)
{
	pos->data = pos->next->data;
	ListNode *del = pos->next;
	pos->next = pos->next->next;
	free(del);
}
//��һ����ͷ������ķ�β���ǰ�����㣨���ܱ�����
void InsertNoFirst(ListNode *pos, DataType data)
{
	ListNode *newNode = CreateNode(data);
	newNode->data = pos->data;
	newNode->next = pos->next;
	pos->data = data;
	pos->next = newNode;
}

//��������ĸ��ơ�һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬
//����һ��randomָ��ָ����������е�һ������ڵ����NULL��
//����Ҫ��ʵ�ָ�������������ظ��ƺ��������
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
	// ��������ÿ����㣬���µĽ������ϵĽ����
	CN *cur = list;
	CN *newNode;
	// cur ֻ�����ϵĽ��
	while (cur != NULL) {
		newNode = CreateNode(cur->data);
		newNode->next = cur->next;
		cur->next = newNode;

		cur = newNode->next;
	}

	// ���� random �ֶ�
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

	printf("���Ƴɹ�\n");
}