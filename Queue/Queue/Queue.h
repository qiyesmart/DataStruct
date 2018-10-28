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
//插入
void	QueuePush(Queue *pq, DataType  data)
{
	//申请结点空间
	pq->size++;
	QNode *node = (QNode *)malloc(sizeof(QNode));
	node->data = data;
	node->next = NULL;
	//如果链表为空
	if (pq->rear == NULL)
	{
		pq->front = pq->rear = node;
		return;
	}
	pq->rear->next = node;
	pq->rear = node;
}
//删除
void  QueuePop(Queue *pq)
{
	pq->size--;
	assert(pq != NULL);
	assert(pq->front != NULL);//不能是空队列
	//链表中只有一个结点
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

//返回队首元素
DataType QueueFront(const Queue *pq)
{
	assert(pq != NULL);
	assert(pq->front != NULL);//不能是空队列
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
	//建设编程
	//假设程序正确
	//1.一个非空，一个不为空
	//2.两个都空
	Queue *pEmpty = &(pqs->queue1);
	Queue *pNotEmpty = &(pqs->queue2);
	if (QueueEmpty(pNotEmpty))
	{
		pEmpty = &(pqs->queue2);
		pNotEmpty = &(pqs->queue1);
	}
	//从非空队列中move  size-1个元素到哦空队列中
	while (QueueSize(pNotEmpty) > 1)
	{
		DataType data = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		QueuePush(pEmpty, data);
	}
	//pNotEmpt队列中只剩一个数据
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
	//从非空队列中move  size-1个元素到哦空队列中
	while (QueueSize(pNotEmpty) > 1)
	{
		DataType data = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		QueuePush(pEmpty, data);
	}
	//pNotEmpt队列中只剩一个数据
	DataType r = QueueFront(pNotEmpty);
	QueuePop(pNotEmpty);
	QueuePush(pEmpty, r);

	return r;
}
