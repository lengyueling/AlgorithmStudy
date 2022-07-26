#include <iostream>
#include <map>
using namespace std;
int main()
{
	//容器11:map 红黑树实现
	//和set类似但是维护的是pair类型
	//不存在重复的数据
	//根据第一关键字正序排序
	map<int,int> mp;
	int n, t, s;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>t>>s;
		mp[t] = s;
	}
	//用法:记录同一个值出现的次数
//	for(int i = 0; i < n; i++)
//	{
//		cin>>t;
//		mp[t]++;
//	}
	
	
	//插入 两种方法等价
	//mp.insert({1,2});
	//mp[1] = 2;
	
	//正序遍历
	map<int,int>::iterator it;
	for(it = mp.begin(); it != mp.end(); it++)
	{
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	
	for(auto j : mp)
	{
		cout<<j.first<<" "<<j.second<<endl;
	}
	
	//删除指定元素
	//map可以直接根据对应关键字删除
	mp.erase(3);
	
	//返回1作为关键字出现的次数
	mp.count(1);
	
	
	return 0;
}
