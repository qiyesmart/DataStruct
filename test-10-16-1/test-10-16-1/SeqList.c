#include "SeqList.h"

void SeqListInit(SeqListR *pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;

}
void SeqListDestory(SeqListR *pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;

}

//尾插
void  SeqListPushBack(SeqListR *pSeq, DataType data)
{
	assert(pSeq != NULL);
	if (pSeq->size == MAXSIZE)
	{
		printf("满了\n");
		return;
	}
	pSeq->array[pSeq->size] = data;
	pSeq->size += 1;
}
//头插
void  SeqListPushFront(SeqListR *pSeq, DataType data)
{
	assert(pSeq != NULL);
	if (pSeq->size == MAXSIZE)
	{
		printf("满了\n");
		return;
	}
	//移动数据，从后往前移动
#if 1 //i代表数据下标
	for (int i = pSeq->size - 1; i >= 0; i--)
	{
		pSeq->array[i + 1] = pSeq->array[i];
	}
#else  //j代表空间下标
	for (int j = pSeq->size; j > 0; j--)
	{
		pSeq->array[j] = pSeq->array[j-1];
	}
#endif
	pSeq->array[0] = data;
	pSeq->size++;
}
//中间插入
void SeqListInsrt(SeqListR *pSeq, int pos, DataType data)
{
	assert(pSeq->size < MAXSIZE);
	assert(pos >= 0 && pos <= pSeq->size);
	//i含义是空间下标，取值范围为[pos+1,size],从后往前移动
	for (int i = pSeq->size; i >= pos + 1; i--)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	pSeq->array[pos] = data;
	pSeq->size += 1;
}
//尾删
void  SeqListPopBack(SeqListR *pSeq)
{
	assert(pSeq != NULL);//传入地址不为空
	assert(pSeq->size > 0);//顺序表不为空

	pSeq->size--;

}
//头删
void  SeqListPOpFront(SeqListR *pSeq)
{
	assert(pSeq != NULL);//传入地址不为空
	assert(pSeq->size > 0);//顺序表不为空
	//数据从前往后搬移，i代表空间的下标
	int i = 0;
	for (i = 0; i <= pSeq->size - 2; i++)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--;
}
//从中间删除
void  SeqListErase(SeqListR *pSeq, int pos)
{
	assert(pSeq != NULL);//传入地址不为空
	assert(pSeq->size > 0);//顺序表不为空
	assert(pos >= 0 && pos <= pSeq->size);//这里没有==size的情况
	for (int i = pos; i <= pSeq->size - 2; i++)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--;
}
//查找
//int SeqListFind(const SeqListR *pSeq, DataType data)
//{
//	for (int i = 0; i < pSeq->size; i++)
//	{
//		if (data == pSeq->array[i])
//			return i;
//	}
//	return -1;
//}
int SeqListFind(const SeqListR *pSeq, DataType data)
{
	for (int i = 0; i < pSeq->size; i++) 
	{
		if (data == pSeq->array[i])
		{
			return i;
		}
	}

	return -1;
}
//删除第一个遇到的data，
int SeqListRemove(SeqListR *pSeq, DataType data)
{
	int  pos = SeqListFind(pSeq, data);
	if (pos == -1)
	{
		return -1;
	}
	SeqListErase(pSeq, pos);
}
//删除遇到的所有的data
int SeqListRemoveAll(SeqListR *pSeq, DataType data)
{
	DataType *extra = (DataType *)malloc(sizeof(DataType)*pSeq->size);
	int i = 0;
	int j = 0;
	//新建数组，把不等于data的数据复制到extra
	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->array[i] != data)
		{
			extra[j++] = pSeq->array[i];
		}
	}
	//从extra复制回来
	for (int k = 0; k < j; k++)
	{
		pSeq->array[k] = extra[k];
	}
	pSeq->size = j;
	free(extra);
}
//属性
bool SeqListEmpty(const SeqListR *pSeq)
{
	return pSeq->size == 0;
}
bool SeqListFull(const SeqListR *pSeq)
{
	return pSeq->size == MAXSIZE;
}
int SeqListSizey(const SeqListR *pSeq)
{
	return   pSeq->size;
}
//打印
void SeqListPrint(const SeqListR *pSeq)
{
	int i = 0;
	for (i = 0; i < pSeq->size; i++)
	{
		printf("%d", pSeq->array[i]);
	}
	printf("\n");
}
//选择排序
typedef int  size_t;
void SWAP(DataType *a, DataType *b)
{
	DataType t = *a;
	*a = *b;
	*b = t;
}
void SelectSortOP(SeqListR *pSeq)
{
	size_t minSpace = 0;
	size_t maxSpace = pSeq->size - 1;
	//区间内只剩一个数或者零个数
	

	while (minSpace < maxSpace)
	{
		size_t minPos = minSpace;//假设第一个是最小的
		size_t maxPos = maxSpace;//假设最后个是最大的
		for (size_t j = minSpace; j <= maxSpace; j++)
		{
			if (pSeq->array[j] < pSeq->array[minPos])
			{
				minPos = j;
			}
			if (pSeq->array[j] > pSeq->array[maxPos])
			{
				maxPos = j;
			}
		}
		SWAP(pSeq->array + minSpace, pSeq->array + minPos);
		if (minSpace == maxPos)
		{
			maxPos = minPos;
		}
		SWAP(pSeq->array + maxSpace, pSeq->array + maxPos);

		minSpace++;
		maxSpace--;
	}
}