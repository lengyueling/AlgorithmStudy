#include <iostream>
#include <algorithm>
#include <ctime>
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

//递归的三路快速排序算法
template <typename T>
void __quickSort3Ways(T arr[], int l, int r)
{
	if( r - l <= 15 )
	{
		InsertionSort(arr,l,r);
		return;
	}
	//开始一次划分
	//随机一个标定点
	swap( arr[l], arr[rand()%(r-l+1)+l ] );
	T v = arr[l];
	
	//lt是lessthen的简称 gt是greaterthen的简称
	//循环中保持arr[l+1..lt] < v
	int lt = l;
	//循环中保持arr[gt..r] > v
	int gt = r + 1;
	//循环中保持arr[lt+1..i] ==v
	int i = l + 1;
	while(i < gt)
	{
		if(arr[i] < v)
		{
			swap(arr[i], arr[lt+1]);
			lt++;
			i++;
		}
		else if(arr[i] > v)
		{
			swap(arr[i], arr[gt-1]);
			gt--;	
		}
		else
		{
			i++;
		}
	}
	swap(arr[l], arr[lt]);
	//此时arr[l..lt-1] < v,arr[lt..gt-1] == v,arr[gt..r] >0
	__quickSort3Ways(arr, l, lt-1);
	__quickSort3Ways(arr, gt, r);
}

//三路快排比普通的快排多==povit的部分
//对于包含有大量重复数据的数组, 三路快排有巨大的优势
//对于其他的数据虽然不如优化过的标准快排，但是最坏时间复杂度比较好
//有些语言的内置默认排序就是三路快排
template <typename T>
void QuickSort3Ways(T arr[], int n)
{
	srand(time(NULL));
	__quickSort3Ways( arr, 0, n-1);
}

int main() 
{
	int n = 1000000;
	int* arr = GenerateRandomArray(n,0,n);
	TestSort("QuickSort3Way", QuickSort3Ways, arr, n);
	delete[] arr;
	cout<<"-------------------"<<endl;
	arr = GenerateNearlyOrderedArray(n,200);
	TestSort("NearlyOrdered:QuickSort3Way", QuickSort3Ways, arr, n);
	delete[] arr;
	cout<<"-------------------"<<endl;	
	arr = GenerateRandomArray(n,0,10);
	TestSort("NearlySame:QuickSort3Way", QuickSort3Ways, arr, n);
	delete[] arr;
	return 0;
}
