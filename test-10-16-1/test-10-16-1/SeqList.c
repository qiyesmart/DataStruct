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

//β��
void  SeqListPushBack(SeqListR *pSeq, DataType data)
{
	assert(pSeq != NULL);
	if (pSeq->size == MAXSIZE)
	{
		printf("����\n");
		return;
	}
	pSeq->array[pSeq->size] = data;
	pSeq->size += 1;
}
//ͷ��
void  SeqListPushFront(SeqListR *pSeq, DataType data)
{
	assert(pSeq != NULL);
	if (pSeq->size == MAXSIZE)
	{
		printf("����\n");
		return;
	}
	//�ƶ����ݣ��Ӻ���ǰ�ƶ�
#if 1 //i���������±�
	for (int i = pSeq->size - 1; i >= 0; i--)
	{
		pSeq->array[i + 1] = pSeq->array[i];
	}
#else  //j����ռ��±�
	for (int j = pSeq->size; j > 0; j--)
	{
		pSeq->array[j] = pSeq->array[j-1];
	}
#endif
	pSeq->array[0] = data;
	pSeq->size++;
}
//�м����
void SeqListInsrt(SeqListR *pSeq, int pos, DataType data)
{
	assert(pSeq->size < MAXSIZE);
	assert(pos >= 0 && pos <= pSeq->size);
	//i�����ǿռ��±꣬ȡֵ��ΧΪ[pos+1,size],�Ӻ���ǰ�ƶ�
	for (int i = pSeq->size; i >= pos + 1; i--)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	pSeq->array[pos] = data;
	pSeq->size += 1;
}
//βɾ
void  SeqListPopBack(SeqListR *pSeq)
{
	assert(pSeq != NULL);//�����ַ��Ϊ��
	assert(pSeq->size > 0);//˳���Ϊ��

	pSeq->size--;

}
//ͷɾ
void  SeqListPOpFront(SeqListR *pSeq)
{
	assert(pSeq != NULL);//�����ַ��Ϊ��
	assert(pSeq->size > 0);//˳���Ϊ��
	//���ݴ�ǰ������ƣ�i����ռ���±�
	int i = 0;
	for (i = 0; i <= pSeq->size - 2; i++)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--;
}
//���м�ɾ��
void  SeqListErase(SeqListR *pSeq, int pos)
{
	assert(pSeq != NULL);//�����ַ��Ϊ��
	assert(pSeq->size > 0);//˳���Ϊ��
	assert(pos >= 0 && pos <= pSeq->size);//����û��==size�����
	for (int i = pos; i <= pSeq->size - 2; i++)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--;
}
//����
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
//ɾ����һ��������data��
int SeqListRemove(SeqListR *pSeq, DataType data)
{
	int  pos = SeqListFind(pSeq, data);
	if (pos == -1)
	{
		return -1;
	}
	SeqListErase(pSeq, pos);
}
//ɾ�����������е�data
int SeqListRemoveAll(SeqListR *pSeq, DataType data)
{
	DataType *extra = (DataType *)malloc(sizeof(DataType)*pSeq->size);
	int i = 0;
	int j = 0;
	//�½����飬�Ѳ�����data�����ݸ��Ƶ�extra
	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->array[i] != data)
		{
			extra[j++] = pSeq->array[i];
		}
	}
	//��extra���ƻ���
	for (int k = 0; k < j; k++)
	{
		pSeq->array[k] = extra[k];
	}
	pSeq->size = j;
	free(extra);
}
//����
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
//��ӡ
void SeqListPrint(const SeqListR *pSeq)
{
	int i = 0;
	for (i = 0; i < pSeq->size; i++)
	{
		printf("%d", pSeq->array[i]);
	}
	printf("\n");
}
//ѡ������
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
	//������ֻʣһ�������������
	

	while (minSpace < maxSpace)
	{
		size_t minPos = minSpace;//�����һ������С��
		size_t maxPos = maxSpace;//��������������
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