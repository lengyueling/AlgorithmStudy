#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include "../SortTestHelper.h"
using namespace std;
using namespace SortTestHelper;

//索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
//性质：
//parent(i) = count / 2;
//left child(i) = i * 2;
//right child(i) = i * 2 + 1；  
//索引最大堆
template<typename Item>
class IndexMaxHeap 
{
private:
	Item *data;// 最大索引堆中的数据
	int *indexes;//最大索引堆中的索引, indexes[x] = i 表示堆的第x个元素的值在data[i]中
	int *reverse;//最大索引堆中的反向索引, reverse[i] = x 表示indexes[x] = i
	//当前储存的结点个数
	int count;
	//堆的总容量
	int capacity;
	
	//结点的上浮
	void ShiftUp(int k)
	{
		if(k > 1 && data[indexes[k/2]] < data[indexes[k]])
		{
			swap(indexes[k/2], indexes[k]);
			reverse[indexes[k/2]] = k/2;
			reverse[indexes[k]] = k;
			k/=2;
			ShiftUp(k);
		}
	}
	
	//结点的下坠
	void ShiftDown(int k)
	{
		while(k*2 <= count)
		{
			int j = k*2;
			//选出左右孩子中最大的与父结点交换
			if(j + 1 <= count && data[indexes[j+1]] > data[indexes[j]])
			{
				j += 1;
			}
			if(data[indexes[k]] >= data[indexes[j]])
			{
				break;
			}
			swap(indexes[j],indexes[k]);
			reverse[indexes[j]] = j;
			reverse[indexes[k]] = k;
			k = j;
		}	
	}
	
public:
	IndexMaxHeap(int capacity)
	{
		//定义堆的容量 结点从堆的索引1开始
		data = new Item[capacity + 1];
		indexes = new int[capacity + 1];
		reverse = new int[capacity + 1];
		for(int i = 0; i < capacity; i++)
		{
			reverse[i] = 0;
		}
		count = 0;
		this->capacity = capacity;
	}
	~IndexMaxHeap()
	{
		delete[] data;
		delete[] indexes;
		delete[] reverse;
	}
	int Size()
	{
		return count;
	}
	
	bool IsEmpty()
	{
		return count == 0;
	}
	
	//传入的i对用户而言，是从0索引的
	//但是实际上堆是从1开始索引的
	void Insert(int i, Item item)
	{
		assert(count + 1 <= capacity);
		assert(i + 1 >= 1 && i + 1 <= capacity);
		i++;
		data[i] = item;
		indexes[count+1] = i;
		reverse[i] = count + 1;
		count++;
		ShiftUp(count);
	}
	
	//取出最大值
	Item ExtractMax()
	{
		assert(count > 0);
		Item ret = data[indexes[1]];
		swap(indexes[1], indexes[count]);
		reverse[indexes[1]] = 1;
		reverse[indexes[count]] = 0;
		count--;
		ShiftDown(1);
		return ret;
	}
	
	//取出最大值的索引
	int ExtractMaxIndex()
	{
		assert(count > 0);
		int ret = indexes[1] - 1;
		swap(indexes[1], indexes[count]);
		reverse[indexes[1]] = 1;
		reverse[indexes[count]] = 0;
		count--;
		ShiftDown(1);
		return ret;
	}
	
	bool Contain(int i)
	{
		assert(i + 1 >= 1 && i + 1 <= capacity);
		return reverse[i+1] != 0;
	}
	
	Item GetItem(int i)
	{
		//防止传入的变量越界
		assert(Contain(i));
		return data[i+1];
	}
	
	void Change(int i, Item newItem)
	{
		assert(Contain(i));
		i++;
		data[i] = newItem;
		//如果不使用reverse，需要用O(n)的时间复杂度来Change
		//找到indexes[j] = i,j表示data[i]在堆中的从大到小的顺序的位置
		//之后ShiftUp(j)再ShiftDown(j)，以让indexes[j]在堆中处于正确的位置
//		for(int j = 0; j <= count; j++)
//		{
//			if(indexes[j] == i)
//			{
//				ShiftUp(j);
//				ShiftDown(j);
//				return;
//			}
//		}

		//有了 reverse 之后
		//我们可以非常简单的通过reverse直接定位索引i在indexes中的位置
		//时间复杂度为O(1)
		int j = reverse[i];
		ShiftUp(j);
		ShiftDown(j);
		
	}
	
	// 测试索引堆中的索引数组index和反向数组reverse
	// 注意:这个测试在向堆中插入元素以后, 不进行extract操作有效
	bool TestIndexesAndReverseIndexes()
	{
		int *copyIndexes = new int[count+1];
		int *copyReverseIndexes = new int[count+1];
		
		for( int i = 0 ; i <= count ; i ++ )
		{
			copyIndexes[i] = indexes[i];
			copyReverseIndexes[i] = reverse[i];
		}
		
		copyIndexes[0] = copyReverseIndexes[0] = 0;
		sort(copyIndexes, copyIndexes + count + 1);
		sort(copyReverseIndexes, copyReverseIndexes + count + 1);
		
		// 在对索引堆中的索引和反向索引进行排序后,
		// 两个数组都应该正好是1...count这count个索引
		bool res = true;
		for( int i = 1 ; i <= count ; i ++ )
		{
			if(copyIndexes[i-1] + 1 != copyIndexes[i] ||copyReverseIndexes[i-1] + 1 != copyReverseIndexes[i] )
			{
				res = false;
				break;
			}
		}
		delete[] copyIndexes;
		delete[] copyReverseIndexes;
		
		if(!res )
		{
			cout<<"Error!"<<endl;
			return false;
		}
		
		for(int i = 1 ; i <= count ; i ++ )
		{
			if(reverse[ indexes[i] ] != i )
			{
				cout<<"Error 2"<<endl;
				return false;
			}
		}
		return true;
	}
	
};

template<typename T>
void HeapSortUsingIndexMaxHeap(T arr[], int n)
{
	IndexMaxHeap<T> indexMaxHeap = IndexMaxHeap<T>(n);
	for( int i = 0 ; i < n ; i++ )
	{
		indexMaxHeap.Insert(i , arr[i] );
	}
	assert( indexMaxHeap.TestIndexesAndReverseIndexes() );
	for( int i = n-1 ; i >= 0 ; i-- )
	{
		arr[i] = indexMaxHeap.ExtractMax();
	}
}

//之所以要使用索引堆，是因为频繁的对data数据进行交换比较消耗新能，特别是data数据比较大的时候
//使用index后插入和删除操作仅对index进行操作，而index数组对应的值记录了data的位置，不需要再对data进行交换
//加入rev则进一步优化性能，仅需要O(1)的时间复杂度就可以检索到index的位置进而获取data的值（利用了数组随机存取的特性）
int main()
{
	int n = 1000000;
	int* arr = GenerateRandomArray(n, 0, n);
	TestSort("HeapSortUsingIndexMaxHeap", HeapSortUsingIndexMaxHeap, arr, n);
	delete[] arr;
	
	return 0;
}
