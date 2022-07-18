#ifndef INC_03_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H
#define INC_03_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper {

    // 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR]
    int *GenerateRandomArray(int n, int rangeL, int rangeR) 
	{
		//rangeL始终小于rangeR
        assert(rangeL <= rangeR);
		
        int *arr = new int[n];
		//随机种子设置
        srand(time(NULL));
        for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
        return arr;
    }
	
	// 生成一个近乎有序的数组
	// 首先生成一个含有[0...n-1]的完全有序数组, 之后随机交换swapTimes对数据
	// swapTimes定义了数组的无序程度:
	// swapTimes == 0 时, 数组完全有序
	// swapTimes 越大, 数组越趋向于无序
	int *GenerateNearlyOrderedArray(int n, int swapTimes)
	{
		
		int *arr = new int[n];
		for(int i = 0 ; i < n ; i ++ )
		{
			arr[i] = i;
		}	
		srand(time(NULL));
		for( int i = 0 ; i < swapTimes ; i ++ )
		{
			//随机找两个数组的位置进行交换
			int posx = rand()%n;
			int posy = rand()%n;
			swap( arr[posx] , arr[posy] );
		}
		return arr;
	}

    // 打印arr数组的所有内容
    template<typename T>
    void PrintArray(T arr[], int n) 
	{
        for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}     
        cout << endl;

        return;
    }
	
	// 判断arr数组是否有序
	template<typename T>
	bool IsSorted(T arr[], int n) 
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				return false;
			}
				
		}	
		return true;
	}
	
	//测试sort排序算法排序arr数组所得到结果的正确性和算法运行时间
	template<typename T>
	void TestSort(const string &sortName,void(*sort)(T[],int),T arr[], int n)
	{
		clock_t startTime = clock();
		sort(arr,n);
		clock_t endTime = clock();
		cout<<sortName <<":"<<double(endTime - startTime) / CLOCKS_PER_SEC<<"s"<<endl;
		assert(IsSorted(arr,n) == true);
		return;
	}
	
	// 拷贝整型数组a中的所有元素到一个新的数组, 并返回新的数组
	int *CopyIntArray(int a[], int n)
	{
		int *arr = new int[n];
		copy(a, a+n, arr);
		return arr;
	}

};
#endif
