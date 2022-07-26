#include <iostream>
#include <set>
using namespace std;
int main()
{
	//容器10:set 红黑树实现
	//不存在重复的数据
	//正序排序
	set<int> se;
	int n,t;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>t;
		//插入
		se.insert(t);
	}
	//迭代器遍历
	set<int>::iterator it;
	for(it = se.begin(); it != se.end(); it++)
	{
		cout<<*it<<" ";
	}
	
	cout<<endl;
	
	//for循环中的auto遍历
	for(auto j : se)
	{
		cout<<j<<" ";
	}
	
	cout<<endl;
	
	//倒序遍历
	set<int>::reverse_iterator it1;
	for(it1 = se.rbegin(); it1 != se.rend(); it1++)
	{
		cout<<*it1<<" ";
	}
	
	cout<<endl;
	
	//查找3 如果查找不到会返回se.end()
	//用法：可以通过j++ j--获取比j大一位或者小一位的数
	auto j = se.find(3);
	if(j == se.end())
	{
		cout<<"did not find"<<endl;
	}
	else
	{
		cout<<*j<<endl;
	}
	
	//返回>=3的第一个数(二分查找)
	//要求是有序数组,不存在这个数则返回end()
	j = se.lower_bound(3);
	//返回<=3的第一个数
	j = se.upper_bound(3);
	
	//删除指定元素
	//set可以直接删除值
	//vector只能通过指针删除
	se.erase(3);
	for(auto it = se.begin(); it != se.end();)
	{
		if(*it == 4)
		{
			it = se.erase(it);
		}
		else
		{
			it++;
		}
	}
	for(auto j : se)
	{
		cout<<j<<" ";
	}
	//返回1出现的次数
	se.count(1);
	
	//清空set
	se.clear();
	
	return 0;
}
