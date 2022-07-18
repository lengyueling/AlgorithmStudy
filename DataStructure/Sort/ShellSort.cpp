#include <iostream>
#include "../SortTestHelper.h"

using namespace std;
using namespace SortTestHelper;

//增量的希尔排序
//时间复杂度与增量序列有关，不是很好计算
template<typename T>
void ShellSort(T arr[], int n){
	
	// 计算增量序列 1, 4, 13, 40, 121, 364, 1093...
	int h = 1;
	while( h < n/3 )
	{
		h = 3 * h + 1;
	}
	//对数组进行多次插入排序，每次排序就让数组更加有序一点
	while( h >= 1 )
	{
		//一次插入排序
		for( int i = h ; i < n ; i++ )
		{
			T e = arr[i];
			int j;
			for( j = i ; j >= h && e < arr[j-h] ; j -= h )
			{
				arr[j] = arr[j-h];
			}	
			arr[j] = e;
		}
		
		h /= 3;
	}
}

int main() {
	// 希尔排序是四种排序算法中性能最优的排序算法
	int n = 20000;
	int *arr = GenerateRandomArray(n, 0, n);
	TestSort("ShellSort", ShellSort, arr, n);
	delete[] arr;
	arr = GenerateNearlyOrderedArray(n,200);
	TestSort("NearlyOrdered:ShellSort", ShellSort, arr, n);
	delete[] arr;
	arr = GenerateNearlyOrderedArray(n,0);
	TestSort("NearlyOrdered:ShellSort", ShellSort, arr, n);
	delete[] arr;
	return 0;
}
