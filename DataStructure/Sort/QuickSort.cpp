#include <iostream>
#include <algorithm>
#include "../SortTestHelper.h"
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

// 对arr[l...r]部分进行一次划分
// 返回j, 使得arr[l...j-1] < arr[j] ; arr[j+1...r] > arr[j]
template <typename T>
int __partition(T arr[], int l, int r)
{	
	//优化2：随机选择划分的基准点
	//随机在arr[l...r]的范围中, 选择一个数值作为标定点
	//对于近乎有序的数据效果会很好，否则对于完全有序的数据时间复杂度会退化为O(n^2)
	swap(arr[l], arr[rand()%(r - l + 1) + l]);
	T v = arr[l];
	int j = l; 
	// arr[l+1...j] < v ; arr[j+1...i) > v
	for(int i = l + 1; i <= r; i++ )
	{
		if( arr[i] < v )
		{
			j++;
			swap( arr[j] , arr[i] );
		}
	}
	swap( arr[l], arr[j]);
	return j;
}

//优化3：换一种划分方式，让==基准点的元素尽量均匀的分布在两边，对于重复数据有较好效果
template <typename T>
int __partition2(T arr[], int l, int r)
{	
	swap(arr[l], arr[rand()%(r - l + 1) + l]);
	T v = arr[l];
	int i = l + 1,j = r; 
	// arr[l+1...j) <= v ; arr(j...r) > v
	while(true)
	{
		//i<=r防止越界
		while(i<=r && arr[i] < v)
		{
			i++;
		}
		//j>=l+1防止越界
		while(j>= l + 1 && arr[j] > v)
		{
			j--;
		}
		if(i >= j)
		{
			break;
		}
		swap(arr[i], arr[j]);
		i++;
		j--;
		
	}
	swap(arr[l], arr[j]);
	return j;
}

//对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r)
{
	//递归终止条件（优化1前）
	//	if(l >= r)
	//	{
	//		return;
	//	}
	//优化1：不使用上面的终止条件，而是当l-r小于某个数值时，进行插入排序
	if( r - l <= 15 ){
		InsertionSort(arr, l, r);
		return;
	}
	//进行一次划分(使用优化3的划分方法)
	int p = __partition2(arr, l, r);
	__quickSort(arr, l, p-1 );
	__quickSort(arr, p+1, r);
}

//增序的快速排序 时间复杂度为O(nlogn)
template <typename T>
void QuickSort(T arr[], int n)
{
	//优化2：随机选择划分的基准点
	//对于近乎有序的数据效果会很好，否则对于完全有序的数据时间复杂度会退化为O(n^2)
	srand(time(NULL));
	__quickSort(arr, 0, n-1);
}



int main()
{
	int n = 1000000;
	int* arr = GenerateRandomArray(n,0,n);
	TestSort("QuickSort", QuickSort, arr, n);
	delete[] arr;
	cout<<"-------------------"<<endl;
	arr = GenerateNearlyOrderedArray(n,200);
	TestSort("NearlyOrdered:QuickSort", QuickSort, arr, n);
	delete[] arr;
	cout<<"-------------------"<<endl;	
	arr = GenerateRandomArray(n,0,10);
	TestSort("NearlySame:QuickSort", QuickSort, arr, n);
	delete[] arr;
	return 0;
}
