#include<iostream>
#include <cassert>
#include <ctime>
using namespace std;

//二分查找法，在有序数组arr中查找出target
//如果能够找到target，则返回对应的索引
//如果没有找到target，则返回-1
//时间复杂度为O(logn)
template<typename T>
int BinarySearch(T arr[], int n, T target)
{
	//在arr[l..r]之中查找target
	int l = 0, r = n - 1;
	while (l <= r)
	{
		//优化1：下面第一种求mid方法可能出现l+r后溢出的情况
		//所以使用新的方法让int不溢出
		//int mid = (l + r)/2;
		int mid = l + (r - l) / 2;
		if (arr[mid] == target)
		{
			return mid;
		}
		//在arr[l..mid-1]之中查找target
		if (target < arr[mid])
		{
			r = mid - 1;
		}
		else//在arr[mid+1..r]之中查找target
		{
			l = mid + 1;
		}
	}
	return -1;
}

int main()
{
	int n = 1000000;
	int* a = new int[n];
	//给二分查找提供顺序的数组
	for (int i = 0 ; i < n ; i ++ )
	{
		a[i] = i;
	}
	// 测试非递归二分查找法
	clock_t startTime = clock();
	for (int i = 0 ; i < 2 * n ; i ++ )
	{
		int v = BinarySearch(a, n, i);
		if ( i < n )
		{
			assert(v == i );
		}
		else
		{
			assert(v == -1 );
		}
	}
	clock_t endTime = clock();
	cout << "BinarySearch : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	return 0;
}
