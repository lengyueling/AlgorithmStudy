#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int main()
{
	//哈希表
	//容器12:hashset
	//容器13:hashmap
	//无自动排序，有去重，支持 O(1) 时间查找元素是否存在
	//map、set使用红黑树为 O(logn)
	
	unordered_map<int, int> ump;
	unordered_set<int> ums;

	ump.insert({ 1, 2 });
	ump[1] = 2;
	ump[2] = 3;
	
	ums.insert(3);
	ums.insert(4);

	for (auto j : ump)
	{
		cout<<j.first<<" "<<j.second<<endl;
	}
	
	cout<<endl;
	
	for (auto j : ums)
	{
		cout << j << endl;
	}
	cout<<endl;
	
	//查找元素是否存在，存在就返回true，否则返回false
	bool t = ump.count(3);
	bool g = ums.count(1);
	cout<<t<<g;
	return 0;
}
