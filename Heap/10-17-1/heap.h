#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct  Heap{
	int array[100];
	int    size;
} Heap;
//�ѵĳ�ʼ��
void HeapInit(Heap *pH, int source[], int size);
//������
void HeapMake1(Heap *pH);//�ݹ�
void HeapMake2(Heap *pH);//�ǵݹ�
//�ѵ�ɾ��
void HeapPop(Heap *pH);
//�ѵĲ���
void HeapPush(Heap *pH, int data);
//�Ѵ�ӡ
void Print(const Heap *pH);
void Print2(int array[], int size);
