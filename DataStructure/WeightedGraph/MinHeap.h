#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include <algorithm>
#include <cassert>
using namespace std;

//最小堆
template<typename Item>
class MinHeap
{
	private:
		Item *data;
		int count;
		int capacity;

		void ShiftUp(int k)
		{
			while ( k > 1 && data[k / 2] > data[k] )
			{
				swap( data[k / 2], data[k] );
				k /= 2;
			}
		}

		void ShiftDown(int k)
		{
			while ( 2 * k <= count )
			{
				int j = 2 * k;
				if ( j + 1 <= count && data[j + 1] < data[j] ) 
				{
					j ++;
				}
				if ( data[k] <= data[j] ) 
				{
					break;
				}
				swap( data[k], data[j] );
				k = j;
			}
		}

	public:
		// 构造函数, 构造一个空堆, 可容纳capacity个元素
		MinHeap(int capacity)
		{
			data = new Item[capacity + 1];
			count = 0;
			this->capacity = capacity;
		}

		//构造函数, 通过一个给定数组创建一个最小堆
		//该构造堆的过程, 时间复杂度为O(n)
		MinHeap(Item arr[], int n)
		{
			data = new Item[n + 1];
			capacity = n;

			for ( int i = 0 ; i < n ; i ++ )
			{
				data[i + 1] = arr[i];
			}	
			count = n;

			for ( int i = count / 2 ; i >= 1 ; i -- )
			{
				ShiftDown(i);
			}	
		}

		~MinHeap()
		{
			delete[] data;
		}

		// 返回堆中的元素个数
		int Size()
		{
			return count;
		}

		// 返回一个布尔值, 表示堆中是否为空
		bool IsEmpty()
		{
			return count == 0;
		}

		// 向最小堆中插入一个新的元素 item
		void Insert(Item item)
		{
			assert( count + 1 <= capacity );
			data[count + 1] = item;
			ShiftUp(count + 1);
			count ++;
		}

		// 从最小堆中取出堆顶元素, 即堆中所存储的最小数据
		Item ExtractMin()
		{
			assert( count > 0 );
			Item ret = data[1];
			swap( data[1], data[count] );
			count --;
			ShiftDown(1);
			return ret;
		}

		// 获取最小堆中的堆顶元素
		Item GetMin()
		{
			assert( count > 0 );
			return data[1];
		}
};
#endif
