#pragma once
#include<assert.h>
#include<stdlib.h>
typedef   int DataType;
typedef  struct  QNode{
	DataType  data;
	struct QNode *next;

}QNode;


typedef  struct  Queue{
	QNode *front;
	QNode  *rear;
	int size;
}Queue;

void QueueInit(Queue *pq)
{
	assert(pq != NULL);
	pq->front = pq->rear = NULL;
}
void  QueueDestory(Queue *pq)
{
	QNode *cur, *next;
	for (cur = pq->front; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	pq->front = pq->rear = NULL;
}
//����
void	QueuePush(Queue *pq, DataType  data)
{
	//������ռ�
	pq->size++;
	QNode *node = (QNode *)malloc(sizeof(QNode));
	node->data = data;
	node->next = NULL;
	//�������Ϊ��
	if (pq->rear == NULL)
	{
		pq->front = pq->rear = node;
		return;
	}
	pq->rear->next = node;
	pq->rear = node;
}
//ɾ��
void  QueuePop(Queue *pq)
{
	pq->size--;
	assert(pq != NULL);
	assert(pq->front != NULL);//�����ǿն���
	//������ֻ��һ�����
	if (pq->front == pq->rear)
	{
		free(pq->front);
		pq->front = pq->rear = NULL;
	}
	else
	{
		QNode *del = pq -> front;
		pq->front = pq->front->next;
		free(del);
	}
}

//���ض���Ԫ��
DataType QueueFront(const Queue *pq)
{
	assert(pq != NULL);
	assert(pq->front != NULL);//�����ǿն���
	return pq->front->data;
}

int QueueEmpty(const Queue *pq)
{
	return pq->front == NULL ? 1 : 0;
}

int QueueSize(const Queue *pq)
{
	return pq->size;
}

typedef  struct QueueStack
{
	Queue   queue1;
	Queue   queue2;
}QStack;
void  QSInit(QStack *pqs)
{
	QueueInit(&(pqs->queue1));
	QueueInit(&(pqs->queue2));
}

void  QSDestory(QStack *pqs)
{
	QueueDestory(&(pqs->queue1));
	QueueDestory(&(pqs->queue2));
}

void  QSPush(QStack *pqs, DataType data)
{
	Queue  *pNotEmpty = &(pqs->queue2);
	if (QueueEmpty(pNotEmpty))
	{
		pNotEmpty = &(pqs->queue1);
	}
	QueuePush(pNotEmpty, data);
}
void  QSPop(QStack *pqs)
{
	//������
	//���������ȷ
	//1.һ���ǿգ�һ����Ϊ��
	//2.��������
	Queue *pEmpty = &(pqs->queue1);
	Queue *pNotEmpty = &(pqs->queue2);
	if (QueueEmpty(pNotEmpty))
	{
		pEmpty = &(pqs->queue2);
		pNotEmpty = &(pqs->queue1);
	}
	//�ӷǿն�����move  size-1��Ԫ�ص�Ŷ�ն�����
	while (QueueSize(pNotEmpty) > 1)
	{
		DataType data = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		QueuePush(pEmpty, data);
	}
	//pNotEmpt������ֻʣһ������
	QueuePop(pNotEmpty);

}
DataType  QSTop(QStack *pqs)
{
	Queue *pEmpty = &(pqs->queue1);
	Queue *pNotEmpty = &(pqs->queue2);
	if (QueueEmpty(pNotEmpty))
	{
		pEmpty = &(pqs->queue2);
		pNotEmpty = &(pqs->queue1);
	}
	//�ӷǿն�����move  size-1��Ԫ�ص�Ŷ�ն�����
	while (QueueSize(pNotEmpty) > 1)
	{
		DataType data = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		QueuePush(pEmpty, data);
	}
	//pNotEmpt������ֻʣһ������
	DataType r = QueueFront(pNotEmpty);
	QueuePop(pNotEmpty);
	QueuePush(pEmpty, r);

	return r;
}
