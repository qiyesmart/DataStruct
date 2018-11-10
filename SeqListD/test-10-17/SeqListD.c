#include "SeqListD.h"

void SeqListDInit(SeqListD *seq)
{
	const int init_capacity = 5;
	assert(seq != NULL);
	assert(seq->array != NULL);
	seq->size = 0;
	seq->capacity = init_capacity;
	seq->array = (DDateType*)malloc(sizeof(DDateType)*init_capacity);
}
void    SeqListDDestory(SeqListD *seq)
{
	free(seq->array);
	seq->array = NULL;
	seq->size = 0;
	seq->capacity = 0;
}
//������Ҫ����/β��
void ExpandIfRequired(SeqListD *seq)
{
	//����Ҫ����
	if (seq->size < seq->capacity)
	{
		return;
	}
	//�϶�Ҫ����
	int newCapacity = seq->capacity * 2;
	DDateType *newArray = (DDateType *)malloc(sizeof(DDateType)*newCapacity);
	assert(newArray);
	//�����ϵ����ݵ��µ�����
	for (int i = 0; i < seq->size; i++)
	{
		newArray[i] = seq->array[i];
	}
	//�ͷ�������
	free(seq->array);
	//������ŵ�˳���ṹ��
	seq->array = newArray;
	//����capacity
	seq->capacity = newCapacity;
}
void  SeqListDPushBack(SeqListD *seq,DDateType data)
{
	assert(seq);
	//��Ҫ��������
	ExpandIfRequired(seq);
	seq->array[seq->size++] = data;
}

void Test()
{
	SeqListD     seq;

	SeqListDInit(&seq);
}