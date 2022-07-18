#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include "../SortTestHelper.h"
using namespace std;
using namespace SortTestHelper;

//性质：
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
	
	//结点的上浮
	void ShiftUp(int k)
	{
		if(k > 1 && data[k/2] < data[k])
		{
			swap(data[k/2], data[k]);
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
	Item ExtractMax()
	{
		assert(count > 0);
		Item ret = data[1];
		swap(data[1], data[count]);
		count--;
		ShiftDown(1);
		return ret;
	}
	
	// 以树状打印整个堆结构
	void TestPrint()
	{
		cout<<"The max heap size is: "<<Size()<<endl;
		cout<<"Data in the max heap: ";
		for( int i = 1 ; i <= Size() ; i ++ )
		{
			// 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
			assert( data[i] >= 0 && data[i] < 100 );
			cout<<data[i]<<" ";
		}
		cout<<endl;
		cout<<endl;
		
		int n = Size();
		int max_level = 0;
		int number_per_level = 1;
		while( n > 0 ) 
		{
			max_level += 1;
			n -= number_per_level;
			number_per_level *= 2;
		}
		
		int max_level_number = int(pow(2, max_level-1));
		int cur_tree_max_level_number = max_level_number;
		int index = 1;
		for( int level = 0 ; level < max_level ; level ++ )
		{
			string line1 = string(max_level_number*3-1, ' ');
			
			int cur_level_number = min(count-int(pow(2,level))+1,int(pow(2,level)));
			bool isLeft = true;
			for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ )
			{
				putNumberInLine( data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
				isLeft = !isLeft;
			}
			cout<<line1<<endl;
			
			if( level == max_level - 1 )
				break;
			
			string line2 = string(max_level_number*3-1, ' ');
			for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
			{
				putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
			}
				
			cout<<line2<<endl;
			
			cur_tree_max_level_number /= 2;
		}
	}
	private:
		void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft)
		{
			int sub_tree_width = (cur_tree_width - 1) / 2;
			int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
			assert(offset + 1 < line.size());
			if( num >= 10 ) 
			{
				line[offset + 0] = '0' + num / 10;
				line[offset + 1] = '0' + num % 10;
			}
			else
			{
				if( isLeft)
				{
					line[offset + 0] = '0' + num;
				}
				else
				{
					line[offset + 1] = '0' + num;
				}	
			}
		}
		
		void putBranchInLine( string &line, int index_cur_level, int cur_tree_width)
		{
			int sub_tree_width = (cur_tree_width - 1) / 2;
			int sub_sub_tree_width = (sub_tree_width - 1) / 2;
			int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
			assert( offset_left + 1 < line.size() );
			int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
			assert( offset_right < line.size() );
			line[offset_left + 1] = '/';
			line[offset_right + 0] = '\\';
		}
};

int main()
{
	//堆建立完成后从1号索引到count索引形成了从大到小的排序
	MaxHeap<int> maxHeap = MaxHeap<int>(100);
	srand(time(NULL));
	for(int i = 0; i < 15; i++)
	{
		maxHeap.Insert(rand() % 100);
	}
	maxHeap.TestPrint();
	for(int i = 0; i < 15; i++)
	{
		maxHeap.ExtractMax();
		maxHeap.TestPrint();
	}
	return 0;
}
