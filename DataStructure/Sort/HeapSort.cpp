#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include "../SortTestHelper.h"
using namespace std;
using namespace SortTestHelper;

//性质（从1开始索引）：
//parent(i) = count / 2;
//left child(i) = i * 2;
//right child(i) = i * 2 + 1；
template<typename Item>
class MaxHeap 
{
private:
	Item *data;
	//当前储存的结点个数
	int count;
	int capacity;
	
	void ShiftUp(int k)
	{
		if(k > 1 && data[k/2] < data[k])
		{
			swap(data[k/2], data[k]);
			k/=2;
			ShiftUp(k);
		}
	}
	
	void ShiftDown(int k)
	{
		while(k*2 <= count)
		{
			int j = k*2;
			//选出左右孩子中最大的与父结点交换
			if(j + 1 <= count && data[j+1] > data[j])
			{
				j += 1;
			}
			if(data[k] >= data[j])
			{
				break;
			}
			swap(data[j],data[k]);
			k = j;
		}	
	}
	
public:
	MaxHeap(int capacity)
	{
		//定义堆的容量 结点从堆的索引1开始
		data = new Item[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	
	//heapify方法实现的构造函数
	//将n个元素插入空堆时间复杂度为O(nlogn)
	//heapify的过程使用O(n)的时间复杂度就给堆的所有节点插入数值
	//所以能够快了不少
	MaxHeap(Item arr[], int n)
	{
		data = new Item[n+1];
		capacity = n;
		
	
		for(int i = 0; i < n; i++)
		{
			data[i+1] = arr[i];
		}
		count = n;
		//对除了最下层结点进行下坠操作
		for(int i = count/2; i>= 1; i--)
		{
			ShiftDown(i);
		}
	}
	
	~MaxHeap()
	{
		delete[] data;
	}
	int Size()
	{
		return count;
	}
	
	bool IsEmpty()
	{
		return count == 0;
	}
	
	void Insert(Item item)
	{
		assert(count + 1 < capacity);
		data[count + 1] = item;
		count++;
		ShiftUp(count);
	}
	
	//取出最大值
	Item ExtractmMax()
	{
		assert(count > 0);
		Item ret = data[1];
		swap(data[1], data[count]);
		count--;
		ShiftDown(1);
		return ret;
	}
};

//初始版本的堆排序 O(nlogn)的时间复杂度
template<typename T>
void HeapSort1(T arr[], int n)
{
	MaxHeap<T> maxHeap = MaxHeap<T>(n+1);
	for(int i = 0; i < n; i++)
	{
		maxHeap.Insert(arr[i]);
	}
	
	for(int i = n-1; i >= 0; i--)
	{
		arr[i] = maxHeap.ExtractmMax();
	}
}


template<typename T>
void HeapSort2(T arr[], int n)
{
	MaxHeap<T> maxHeap = MaxHeap<T>(arr,n);
	
	for(int i = n-1; i >= 0; i--)
	{
		arr[i] = maxHeap.ExtractmMax();
	}
}

template<typename T>
void __shiftDown(T arr[], int n, int k)
{
	while(k*2+1 < n)
	{
		int j = k*2;
		//选出左右孩子中最大的与父结点交换
		if(j + 1 <= n && arr[j+1] > arr[j])
		{
			j += 1;
		}
		if(arr[k] >= arr[j])
		{
			break;
		}
		swap(arr[j],arr[k]);
		k = j;
	}	
}

//从0开始索引：
//parent(i) = (count-1) / 2;
//left child(i) = i * 2 + 1;
//right child(i) = i * 2 + 2；  
template<typename T>
void HeapSort3(T arr[], int n)
{
	//heapify构建最大堆
	for(int i = (n-1)/2; i >= 0; i--)
	{
		__shiftDown(arr, n, i);
	}
	
	for(int i = n-1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		__shiftDown(arr, i, 0);
	}
}

int main()
{	
	int n = 1000000;
	int* arr = GenerateRandomArray(n,0,n);
	int* arr2 = CopyIntArray(arr,n);
	int* arr3 = CopyIntArray(arr,n);
	TestSort("HeapSortNormal", HeapSort1, arr, n);
	TestSort("HeapSortHeapify", HeapSort2, arr3, n);
	TestSort("HeapSort", HeapSort3, arr3, n);
	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	cout<<"-------------------"<<endl;
	arr = GenerateNearlyOrderedArray(n,200);
	arr2 = CopyIntArray(arr,n);
	arr3 = CopyIntArray(arr,n);
	TestSort("NearlyOrdered:HeapSortNormal", HeapSort1, arr, n);
	TestSort("NearlyOrdered:HeapSortHeapify", HeapSort2, arr2, n);
	TestSort("NearlyOrdered:HeapSort", HeapSort3, arr3, n);
	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	cout<<"-------------------"<<endl;	
	arr = GenerateRandomArray(n,0,10);
	arr2 = CopyIntArray(arr,n);
	arr3 = CopyIntArray(arr,n);
	TestSort("NearlySame:HeapSortNormal", HeapSort1, arr, n);
	TestSort("NearlySame:HeapSortHeapify", HeapSort2, arr2, n);
	TestSort("NearlySame:HeapSort", HeapSort3, arr3, n);
	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	return 0;
}
