#include"heap.h"

void HeapInit(Heap *pH, int source[], int size)
{
	for (int i = 0; i < size; i++)
	{
		pH->array[i] = source[i];
	}
	pH->size = size;
}

//������
void   HeapAdjustDown(Heap *pH, int root)
{
	//���ж���û�к��ӣ�Ҷ�ӽ�㣩��
	//��������Ƕ�ȥ��->���ӵ��±��Ƿ�Խ�磻
	//ֻ��Ҫ�ж����ӵ��±�(��Ϊ����ȫ��������
	int left = root * 2 + 1;
	int right = root * 2 + 2;
	if (left >= pH->size)
	{
		//�Ѿ�Խ��
		return;
	}
	//һ��������
	int maxChild = left;
	if (2 * root + 2 < pH->size && pH->array[2 * root + 2] > pH->array[left])
	{
		//ǰһ���ж��Ƿ����к��ӣ���һ���ж��к����Ƿ��������
		maxChild = right;
	}
	if (pH->array[root] > pH->array[maxChild])
	{
		return;
	}
	//����root��maxChild���ڵ��±�ֵ
	int t = pH->array[root];
	pH->array[root] = pH->array[maxChild];
	pH->array[maxChild] = t;
	//�����ݹ����maxChild
	HeapAdjustDown(pH, maxChild);
}
void HeapMake1(Heap *pH)//�ݹ鴴��
{ //����Ϊ[0��(size-2)/2]
	for (int i = (pH->size - 2) / 2; i >= 0; i--)
	{
		HeapAdjustDown(pH, i);
	}
}

void SWAP(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void HeapAdjustDown2(Heap *pH, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	while (left < pH->size)
	{
		int maxChild = left;
		if (right<pH->size &&pH->array[right]>pH->array[left])
		{
			maxChild = right;
		}
		if (pH->array[right] < pH->array[root])
		{
			break;
		}
		SWAP(pH->array + maxChild, pH->array + root);
		root = maxChild;
		left = 2 * root + 1;
		right = 2 * left + 2;
	}
}
void HeapMake2(Heap *pH)//�ǵݹ鴴��
{ //����Ϊ[0��(size-2)/2]
	for (int i = (pH->size - 2) / 2; i >= 0; i--)
	{
		HeapAdjustDown(pH, i);
	}
}

//�ѵ�ɾ��
void HeapPop(Heap *pH)//���滻�������Ѷ�Ԫ�������һ��Ԫ���滻��Ȼ�����µ���
{
	pH->array[0] = pH->array[pH->size - 1];
	pH->size--;

	HeapAdjustDown(pH, 0);
}

//�Ѳ���
void HeadJustUp(Heap *pH, int child)
{
	int parent;
	while (child > 0)
	{
		parent = (child - 1) / 2;
		if (pH->array[parent] >= pH->array[child])
		{
			return;
		}
		SWAP(pH->array + parent, pH->array + child);

		child = parent;
	}
}
void HeapPush(Heap *pH, int data)
{
	assert(pH->size < 100);
	pH->array[pH->size++] = data;
	HeadJustUp(pH, pH->size - 1);
}

//��ӡ
void Print( Heap *pH)
{
	int i = 0;
	for (i = 0; i < pH->size; i++)
	{
		printf("%d  ", pH->array[i]);
	}
	printf("\n");
}
void Print2(int array[],int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}

void Test1()
{
	int array[] = { 1, 2, 3, 4, 5,6,7 };
	int size = sizeof(array) / sizeof(int);
	Heap    heap;
	HeapInit(&heap, array, size);
	HeapMake2(&heap);
	/*HeapPush(&heap, 100);*/

	Print(&heap);
	/*printf("�ɹ���");*/
}

int main()
{
	Test1();
	system("pause");
	return 0;
}