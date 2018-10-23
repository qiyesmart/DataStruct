
//1.从尾到头打印单链表
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

