#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <assert.h>

template <typename T>
class MyVector
{
private:
	T* data;		//存放数据的数组
	int capacity; 	//容量
	int size;		//储存数组中的元素个数
	
	//重新设置新的数组
	//使用均摊复杂度来降低平均的复杂度
	void resize(int newCapactiry)
	{
		assert(newCapactiry >= size);
		T* newData = new T[newCapactiry];
		//将老的数据存到新开的数组中
		for(int i = 0; i < size; i++)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		capacity = newCapactiry;
	}
public:
	MyVector()
	{
		data = new T[10];
		capacity = 10;
		size = 0;
	}
	~MyVector()
	{
		delete[] data;
	}
	
	//平均复杂度为O(1)
	void push_back(T e)
	{
		if(size == capacity)
		{
			resize(2*capacity);
		}
		assert(size < capacity);
		data[size++] = e;
	}
	
	//平均复杂度为O(1)
	T pop_back()
	{
		assert(size > 0);
		T ret = data[size];
		size --;
		//防止连续pop和push产生复杂度的震荡
		if(size == capacity/4)
		{
			resize(capacity/2);
		}
		return ret;
	}

};

#endif
