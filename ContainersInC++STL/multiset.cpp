#include <iostream>
#include <set>
using namespace std;
int main()
{
	//容器13:multiset  红黑树实现
	//可以存放重复的数据 
	//自动进行正序排序
	multiset<int> se;
	int n, t;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>t;
		se.insert(t);
	}
	//删除指定元素
	se.erase(2);
	for(auto it = se.begin(); it != se.end();)
	{
		if(*it == 3)
		{
			it = se.erase(it);
		}
		else
		{
			it++;
		}
	}
	
	//正序遍历
	for(auto j : se)
	{
		cout<<j<<endl;
	}
	return 0;
}
