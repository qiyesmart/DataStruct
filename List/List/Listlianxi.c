
//1.��β��ͷ��ӡ������
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
void test()
{
	
	    ListNode *first;
		ListInit(&first);
		ListPushBack(&first, 1);
		ListPushBack(&first, 2);
		ListPushBack(&first, 3);
		ListPushBack(&first, 4);
		ListPushBack(&first, 5);

		PrintReverse(first);


}
int main()
{
	test();
	system("pause");
	return 0;
}

