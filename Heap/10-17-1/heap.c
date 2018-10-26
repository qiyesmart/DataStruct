#include"heap.h"

void HeapInit(Heap *pH, int source[], int size)
{
	for (int i = 0; i < size; i++)
	{
		pH->array[i] = source[i];
	}
	pH->size = size;
}

//创建堆
void   HeapAdjustDown(Heap *pH, int root)
{
	//先判断有没有孩子（叶子结点）；
	//按照数组角度去想->孩子的下标是否越界；
	//只需要判断左孩子的下标(因为是完全二叉树）
	int left = root * 2 + 1;
	int right = root * 2 + 2;
	if (left >= pH->size)
	{
		//已经越界
		return;
	}
	//一定有左孩子
	int maxChild = left;
	if (2 * root + 2 < pH->size && pH->array[2 * root + 2] > pH->array[left])
	{
		//前一个判断是否有有孩子，后一个判断有孩子是否大于左孩子
		maxChild = right;
	}
	if (pH->array[root] > pH->array[maxChild])
	{
		return;
	}
	//交换root和maxChild所在的下标值
	int t = pH->array[root];
	pH->array[root] = pH->array[maxChild];
	pH->array[maxChild] = t;
	//继续递归调整maxChild
	HeapAdjustDown(pH, maxChild);
}
void HeapMake1(Heap *pH)//递归创建
{ //区间为[0，(size-2)/2]
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
void HeapMake2(Heap *pH)//非递归创建
{ //区间为[0，(size-2)/2]
	for (int i = (pH->size - 2) / 2; i >= 0; i--)
	{
		HeapAdjustDown(pH, i);
	}
}

//堆的删除
void HeapPop(Heap *pH)//用替换法，将堆顶元素用最后一个元素替换，然后向下调整
{
	pH->array[0] = pH->array[pH->size - 1];
	pH->size--;

	HeapAdjustDown(pH, 0);
}

//堆插入
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

//打印
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
	/*printf("成功了");*/
}

int main()
{
	Test1();
	system("pause");
	return 0;
}