#include <iostream>
#include <map>
using namespace std;
int main()
{
	//容器12:multimap  红黑树实现
	//和set类似但是维护的是pair类型
	//可以存放重复的数据 
	//因为数据可能重复 所以不能使用mp[t] = s这种插入方法
	//根据第一关键字正序排序
	multimap<int,int> mp;
	int n, t, s;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>t>>s;
		mp.insert({t, s});
	}
	
	//这样会删除所有的以3位关键字的元素
	mp.erase(3);
	
	//删除指定的关键值和关键字组成的元素
	for(auto it = mp.begin(); it != mp.end();)
	{
		if((*it).first == 3 && (*it).second == 2)
		{
			it = mp.erase(it);
		}
		else
		{
			it++;	
		}
	}
	
	for(auto j : mp)
	{
		cout<<j.first<<" "<<j.second<<endl;
	}
	return 0;
}
