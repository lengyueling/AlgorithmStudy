#include <iostream>
#include <algorithm>
#include "../SortTestHelper.h"
#include "../Student.h"
using namespace std;
using namespace SortTestHelper;

//增序的选择排序 时间复杂度O(n^2)
template<typename T>
void SelectionSort(T arr[],int n)
{
	for(int i = 0; i < n; i++)
	{
		//寻找[i,n]之间的最小值
		int minIndex = i;
		for(int j = i + 1; j < n; j++)
		{
			if(arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		//每一轮排序将最小值放在最前面
		swap(arr[i],arr[minIndex]);
	}
}

int main()
{
	int n = 20000;
	int *arr = GenerateRandomArray(n,0,n);
	SelectionSort(arr,10);
	PrintArray(arr,10);
	delete[] arr;
	cout<<"-------------------"<<endl;
	Student d[4] = { {"D",90} , {"C",100} , {"B",95} , {"A",95} };
	SelectionSort(d,4);
	for( int i = 0 ; i < 4 ; i ++ )
	{
		cout<<d[i];
	}
	cout<<"-------------------"<<endl;
	arr = GenerateRandomArray(n,0,n);
	TestSort("SelectionSort",SelectionSort,arr,n);
	arr = GenerateNearlyOrderedArray(n,200);
	TestSort("NearlyOrdered:SelectionSort", SelectionSort, arr, n);
	return 0;
}

