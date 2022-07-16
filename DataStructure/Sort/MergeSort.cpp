#include <iostream>
#include "SortTestHelper.h"
using namespace std;
using namespace SortTestHelper;

//优化时使用的插入排序
//对arr[l...r]范围的数组进行插入排序
template<typename T>
void InsertionSort(T arr[], int l, int r)
{
	for(int i = l+1; i < r+1; i++ ) 
	{
		T e = arr[i];
		int j;
		for (j = i; j > l && arr[j-1] > e; j--)
		{
			arr[j] = arr[j-1];
		}	
		arr[j] = e;
	}
	return;
}

//将arr[l..mid]和arr[mid+1..r]两部分进行归并
template<typename T>
void __merge(T arr[], int l, int mid, int r)
{
	//建立一个与arr一样的副本aux
	T aux[r - l + 1];
	//对aux进行赋值，记得arr与aux有l的偏移量
	for(int i = l; i <= r; i++)
	{
		aux[i-l] = arr[i];
	}
	//i j为归并两段的开头位置
	int i = l, j = mid + 1;
	for(int k = l; k <= r; k++)
	{
		//如果aux的左边部分已经被选完了
		if(i > mid)
		{
			arr[k] = aux[j-l];
			j++;
		}//如果aux的右边部分已经被选完了
		else if(j > r)
		{
			arr[k] = aux[i-l];
			i++;
		}// 左半部分所指元素 < 右半部分所指元素
		else if(aux[i-l] < aux[j-l])
		{
			arr[k] = aux[i-l];
			i++;
		}// 左半部分所指元素 >= 右半部分所指元素
		else
		{
			arr[k] = aux[j-l];
			j++;
		}
	}
	
}

//递归使用归并排序
template<typename T>
void __mergeSort(T arr[], int l, int r)
{
	//递归终止条件（优化2前）
//	if(l >= r)
//	{
//		return;
//	}
	//优化2：不使用上面的终止条件，而是当l-r小于某个数值时，进行插入排序
	if( r - l <= 15 ){
		InsertionSort(arr, l, r);
		return;
	}
	
	int mid = (l + r) / 2;
	//递归调用归并排序
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	//优化1：如果arr已经有序，则不需要再进行排序了
	//适用于近乎有序的算法，效果会比较好
	if(arr[mid] > arr[mid+1])
	{
		//合并两端 
		__merge(arr, l, mid, r);
	}
}

//增序的归并排序 时间复杂度为O(nlogn)
template<typename T>
void MergeSort(T arr[], int n)
{
	__mergeSort(arr, 0, n-1);
}

//自底向上的归并排序
template<typename T>
void MergeSortBU(T arr[], int n)
{
	//第一轮看1个元素，第二轮看2个元素，第n轮看n^2个元素
	for(int sz = 1; sz < n; sz+=sz)
	{
		//对两个sz大小的区域进行merge操作
		//i + sz < n防止归并的mid的值越界
		//min(i + sz + sz - 1, n-1)防止i += sz + sz（右边边界）越界
		for(int i = 0; i + sz < n; i += (sz + sz))
		{
			// 对 arr[i...i+sz-1] 和 arr[i+sz...i+2*sz-1] 进行归并
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n-1));
		}
	}
}

int main()
{
	int n = 100000;
	int *arr = GenerateRandomArray(n,0,n);
	int *arr2 = CopyIntArray(arr,n);
	TestSort("MergeSort",MergeSort,arr,n);
	TestSort("MergeSortBU",MergeSortBU,arr2,n);
	delete[] arr;
	delete[] arr2;
	return 0;
}
