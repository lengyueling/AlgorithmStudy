#include <iostream>
#include <algorithm>
#include "../SortTestHelper.h"
#include "../Student.h"
using namespace std;
using namespace SortTestHelper;

//增序的插入排序 时间复杂度O(n^2)
template<typename T>
void InsertionSort(T arr[],int n)
{
	//因为只考虑第一个元素时第一个元素一定有序，所以从第二个元素开始考虑
	for(int i = 1; i < n; i++)
	{
		//寻找arr[i]合适的插入位置
		//如果当前元素比前一个元素要小则往前插入，直至插入到当前元素比前一个元素大，提前结束本轮循环
		//理论上因为会提前终止循环，所以会比选择排序耗时更少，但是由于swap操作耗时多，所以实际上可能比选择排序耗时还要多
		for(int j = i; j > 0 && arr[j] < arr[j-1]; j--)
		{
			
			swap(arr[j],arr[j-1]);
		}
	}
}

//增序的插入排序 时间复杂度O(n^2)
template<typename T>
void InsertionSortAdvance(T arr[], int n) 
{
	//因为只考虑第一个元素时第一个元素一定有序，所以从第二个元素开始考虑
	for (int i = 1; i < n; i++) 
	{
		//寻找arr[i]合适的插入位置
		//改进：建立一个副本，与之前元素作比较，直到副本比前一个元素大才把元素插入进去，不使用swap函数
		T e = arr[i];
		//j保存元素e应该插入的位置
		int j;
		for (j = i; j > 0 && arr[j - 1] > e; j--) 
		{
			//把arr[j]往后挪，给arr[i]腾出位置
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
}

int main()
{
	int n = 20000;
	int *arr = GenerateRandomArray(n,0,n);
	int *arr2 = CopyIntArray(arr,n);
	TestSort("InsertionSort",InsertionSort,arr,n);
	TestSort("InsertionSortAdvance", InsertionSortAdvance, arr2, n);
	cout<<"-------------------"<<endl;
	//对于近乎有序的数组，插入排序的时间复杂度接近于O(n)，十分好用
	arr = GenerateNearlyOrderedArray(n,200);
	arr2 = CopyIntArray(arr,n);
	TestSort("NearlyOrdered:ArrayInsertionSorte", InsertionSort, arr, n);
	TestSort("NearlyOrdered:ArrayInsertionSortAdvance", InsertionSortAdvance, arr2, n);
	delete[] arr;
	delete[] arr2;
	return 0;
}

