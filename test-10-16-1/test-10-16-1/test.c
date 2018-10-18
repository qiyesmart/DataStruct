#include "SeqList.h"

void Test()
{
	SeqListR  seqList;
	SeqListInit(&seqList);
	assert(seqList.size == 0);
	/*SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 4);

	SeqListPrint(&seqList);

	SeqListPushFront(&seqList, 0);
	SeqListPrint(&seqList);

	SeqListInsrt(&seqList, 0, -1);
	SeqListPrint(&seqList);
	SeqListPopBack(&seqList);
	SeqListPrint(&seqList);
	SeqListPOpFront(&seqList);
	SeqListPrint(&seqList);
	SeqListErase(&seqList, 3);*/
	/*SeqListPrint(&seqList);*/
	SeqListPushBack(&seqList, 4);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 5);
	SelectSortOP(&seqList);
	SeqListPrint(&seqList);
}
int main()
{
	Test();
	system("pause");
	return 0;
}