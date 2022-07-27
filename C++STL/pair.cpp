#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
int main()
{
	//容器3:pair 
	//关键字 关键值
	//基础用法
//	pair<char, string> a, b;
//	char t;
//	string s;
//	cin>>t>>s;
//	a = {t, s};
//	
//	cout<<a.first<<" "<<a.second;

	//别名用法
	p p1 = p(1, 3);
	p p2 = p(2, 2);
	p p3 = p(0, -2);
	
	vector<p> vec;
	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);
	
	//pair排序
	//pair默认是先对第一个关键字从小到大排序
	//如果第一关键字相同，在对第二关键字从小到大排序
	sort(vec.begin(), vec.end());
	for(auto i : vec)
	{
		cout<<i.first<<" "<<i.second<<endl;
	}
	return 0;
}
