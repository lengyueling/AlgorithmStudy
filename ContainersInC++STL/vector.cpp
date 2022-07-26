#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	//容器1:vector
	//vector可以随开随用,下面的操作类似于二维数组
	//vector<int> vec1[100];
	vector<int> vec;
	int n, t;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>t;
		//从尾部插入t
		vec.push_back(t);
	}
	
	//正序排序
	sort(vec.begin(),vec.end());
	//倒序排序
	//reverse(vec.begin(),vec.end());
	
	//正序遍历
	//迭代器遍历
	vector<int>::iterator it;
	//begin返回第一个元素的迭代器
	//end返回最后一个元素的迭代器
	for(it = vec.begin(); it != vec.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	
	//for循环中的auto,可以遍历容器
	for(auto j:vec)
	{
		cout<<j<<" ";
	}
	cout<<endl;
	
	//vector遍历
	for(int i = 0; i < vec.size(); i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	
	//倒序遍历
	vector<int>::reverse_iterator it1;
	//it1可以直接在for循环内使用auto类型
	for(it1 = vec.rbegin(); it1 != vec.rend(); it1++)
	{
		cout<<*it1<<" ";
	}
	cout<<endl;
	for(int i = vec.size() - 1; i >=0; i--)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	
	//按值删除vec中的元素
	for(auto it = vec.begin(); it != vec.end();)
	{
		if(*it == 4)
		{
			it = vec.erase(it);
		}
		else
		{
			it++;
		}
	}
	for(auto j:vec)
	{
		cout<<j<<" ";
	}
	cout<<endl;
	
	//删除尾部的元素
	vec.pop_back();
	
	if(vec.size())
	{
		//返回第一个元素
		vec.front();
		//返回最后一个元素
		vec.back();
	}
	
	//清空vec
	vec.clear();
	return 0;
}
