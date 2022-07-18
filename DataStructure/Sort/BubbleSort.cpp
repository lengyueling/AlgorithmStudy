#include <iostream>
#include <algorithm>
#include "../SortTestHelper.h"
#include "../Student.h"
using namespace std;
using namespace SortTestHelper;

//增序的冒泡排序 时间复杂度O(n^2)
template<typename T>
void BubbleSort(T arr[], int n) 
{
	for (int i = 1; i < n; i++) 
	{
		//每一轮都让最大的放在最后
		for(int j = 1; j < n; j++)
		{
			if(arr[j-1] > arr[j])
			{
				swap(arr[j-1],arr[j]);
			}
		}
	}
}

template<typename T>
void BubbleSort2( T arr[] , int n)
{
	//优化：如果一次遍历都没有循环说明已经排序完成
	bool swapped;
	do
	{
		swapped = false;
		for( int i = 1 ; i < n ; i++ )
		{
			if( arr[i-1] > arr[i] )
			{
				swap( arr[i-1] , arr[i] );
				swapped = true;
			}
		}
		n--;
		
	}while(swapped);
}

// 优化:每一趟都将最大的元素放在了最后的位置，所以下一次排序最后的元素可以不再考虑
template<typename T>
void BubbleSort3( T arr[] , int n)
{
	int newn; // 使用newn进行优化
	do
	{
		newn = 0;
		for( int i = 1 ; i < n ; i ++ )
		{
			if( arr[i-1] > arr[i] )
			{
				swap( arr[i-1] , arr[i] );
				// 记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
				newn = i;
			}
		}
		n = newn;
	}while((newn > 0));
}

int main() {
	int n = 20000;
	int *arr = GenerateRandomArray(n, 0, n);
	int *arr2 = CopyIntArray(arr,n);
	int *arr3 = CopyIntArray(arr,n);
	TestSort("BubbleSort", BubbleSort, arr, n);
	TestSort("BubbleSort2", BubbleSort2, arr2, n);
	TestSort("BubbleSort3", BubbleSort3, arr3, n);
	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	
	cout<<"-------------------"<<endl;
	arr = GenerateNearlyOrderedArray(n,200);
	arr2 = CopyIntArray(arr,n);
	arr3 = CopyIntArray(arr,n);
	TestSort("NearlyOrdered:BubbleSort", BubbleSort, arr, n);
	TestSort("NearlyOrdered:BubbleSort2", BubbleSort2, arr2, n);
	TestSort("NearlyOrdered:BubbleSort3", BubbleSort3, arr3, n);
	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	
	cout<<"-------------------"<<endl;
	arr = GenerateNearlyOrderedArray(n,0);
	arr2 = CopyIntArray(arr,n);
	arr3 = CopyIntArray(arr,n);
	TestSort("Ordered:BubbleSort", BubbleSort, arr, n);
	TestSort("Ordered:BubbleSort2", BubbleSort2, arr2, n);
	TestSort("Ordered:BubbleSort3", BubbleSort3, arr3, n);
	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	
	return 0;
}

