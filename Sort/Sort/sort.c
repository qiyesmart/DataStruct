#include<stdio.h>
#include<stdlib.h>

//插入排序
void InsertSort(int  array[], int size)
{
	int key;
	int i, j;
	for ( i =1; i < size; i++)
	{
		key = array[i];
		for ( j = i-1 ; j >= 0; j--)
		{
			if (key >= array[j])
			{
				break;
			}
			else
			{
				array[j+1] = array[j];
			}
		}
		array[j+1] = key;
	}
}

//希尔排序
void InsertSort1(int array[], int size, int gap)
{
	for (int g = 0; g < gap; g++)
	{
		int key;
		int i, j;
		for (i = gap + g; i < size; i += gap)
		{
			key = array[i];
			for (j = i - gap; j >= 0; j-=gap)
			{
				if (key >= array[j])
				{
					break;
				}
				else
				{
					array[j + gap] = array[j];
				}
			}
			array[j + gap] = key;
		}
    }  
}
void  ShellSort(int array[], int size)
{
	int gap = size;
	//gap动态变化
	while (1)
	{
		gap = gap / 3 + 1;
		InsertSort1(array, size, gap);
		if (gap == 1)
		{
			break;
		}
	}
}

//选择排序
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void SelectSort1(int array[], int size)
{
	for (int i = size; i > 1; i--)
	{
		int max = 0;
		for (int j = 1; j < i; j++)
		{
			if (array[j]>array[max])
				max = j;
		}
		swap(array + max, array + i - 1);
	}
}
void  SelectSort2(int array[], int size)
{
	int left = 0, right = size - 1;
	while (left < right)
	{
		int min = left, max = left;
		for (int j = left + 1; j <= right; j++)
		{
			if (array[j]>array[max])
			{
				max = j;
			}
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		swap(array + left, array + min);
		if (max == left)
		{
			max = min;
		}
		swap(array + right, array + max);
		left++;
		right--;

	}
}

//堆排序
void   AdjustDown(int array[], int size, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	if (left >= size)
	{
		return;
	}
	int max = left;
	if (right<size&&array[right]>array[left])
	{
		max = right;
	}
	if (array[root] >= array[max])
	{
		return;
	}
	swap(array + root, array + max);
	AdjustDown(array, size, max);
}
void  CreateHeap(int array[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		AdjustDown(array, size, i);
	}
}
void   HeapSort(int array[], int size)
{
	CreateHeap(array, size);
	for (int i = 0; i < size; i++)
	{
		swap(&array[0], &array[size - i - 1]);
		AdjustDown(array, size - i - 1, 0);
	}
}

//冒泡排序
void BubbleSort(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int isSorted = 1;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (array[j]>array[j + 1])
			{
				swap(array + j, array + j + 1);
				isSorted = 0;
			}
		}
		if (isSorted == 1)
		{
			break;
		}
	}
}

//归并排序
//合并数组
void Merge(int array[], int left, int mid, int right, int extra[])
{
	int left_i = left;	// [left, mid)
	int right_i = mid;	// [mid, right)
	int extra_i = left;

	while (left_i < mid && right_i < right) {
		if (array[left_i] <= array[right_i]) {
			extra[extra_i++] = array[left_i++];
		}
		else {
			extra[extra_i++] = array[right_i++];
		}
	}
	//如果左边数据剩余
	while (left_i < mid) {
		extra[extra_i++] = array[left_i++];
	}
	//如果右边数组剩余
	while (right_i < right) {
		extra[extra_i++] = array[right_i++];
	}

	for (int i = left; i < right; i++) {
		array[i] = extra[i];
	}
}
//排序
void MergeSort1(int array[], int left, int right, int extra[])
{
	// [0,1)
	if (left == right - 1) {
		// 区间内只剩一个数，已经有序
		return;
	}

	if (left >= right) {
		// 区间内没有数了
		return;
	}
	/// [left, right)
	// [left, mid)
	// [mid, right)
	int mid = left + (right - left) / 2;
	MergeSort1(array, left, mid, extra);
	MergeSort1(array, mid, right, extra);
	Merge(array, left, mid, right, extra);
}
// 稳定
void MergeSort(int array[], int size)
{
	int *extra = (int *)malloc(sizeof(int)* size);
	MergeSort1(array, 0, size, extra);
	free(extra);
}
//
void MergeSortLoop(int array[], int size)
{
	int *extra = (int *)malloc(sizeof(int)* size);
	for (int i = 1; i < size; i *= 2) {	// 一共循环 log(size)
		for (int j = 0; j < size; j = j + 2 * i) {
			int left = j;
			int mid = j + i;
			int right = mid + i;

			if (mid >= size) {
				continue;
			}

			if (right > size) {
				right = size;
			}

			Merge(array, left, mid, right, extra);
		}
	}
	free(extra);
}

//快速排序
//hover法
int Partition1(int array[], int left, int right)
{
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end && array[begin] <= array[right])
		{
			begin++;
		}
		while (begin < end && array[right] <= array[end])
		{
			right--;
		}
		swap(array + begin, array + end);
	}
	swap(array + begin, array + right);
	return begin;
	
}
//挖坑法
int Partition2(int array[], int left, int right)
{
	int begin = left;	// 不是 0
	int end = right;	// 不是 right - 1
	int pivot = array[right];		// pivot 存的就是基准值

	while (begin < end) {
		// 如果基准值在最右边，想先动 begin
		// array[begin] 要 <= 不能 <
		while (begin < end && array[begin] <= pivot) {
			begin++;
		}

		array[end] = array[begin];

		while (begin < end && array[end] >= pivot) {
			end--;
		}

		array[begin] = array[end];
	}

	array[begin] = pivot;

	return begin;
}
//左右指针法
int Partition3(int array[], int left, int right)
{
	int cur, div;
	for (cur = left, div = left; cur < right; cur++)
	{
		if (array[cur] < array[right])
		{
			swap(array + cur, array + div);
			div++;
		}
	}
	swap(array + div, array + right);
	return div;
}
void QuickSort1(int array[], int left, int right)
{
	if (left == right)
	{
		return;
	}
	if (left > right)
	{
		return;
	}
	//divs是基准值坐在下标
	int div = Partition3(array, left, right);
	QuickSort1(array, left, div - 1);
	QuickSort1(array, div+1, right);
}
void	QuickSort(int array[], int size)
{
	QuickSort1(array, 0, size - 1);
}

void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

void  test()
{
	int array[] = { 3, 5, 1, 4, 7, 8, 2, 6 };
	int size = sizeof(array) / sizeof(int);
	/*InsertSort(array, size);*/
	//ShellSort(array,  size);
	/*SelectSort2(array, size);*/
	/*HeapSort(array, size);*/
	/*MergeSort(array, size);*/
	QuickSort(array, size);
	PrintArray(array, size);
}

int main()
{
	test();
	system("pause");
	return 0;
}