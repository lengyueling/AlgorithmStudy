#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	//容器2:string
	string a, b;
	cin>>a;
	//在容器尾部插入元素
	a.push_back('xxxxxx');
	
	//排序
	sort(a.begin(), a.end());
	cout<<a<<endl;
	//在容器尾部删除元素
	a.pop_back();
	cout<<a<<endl;
	//返回找到第一个b的索引
	cout<<a.find('b')<<endl;
	//从3开始往后截取5个字符,不会越界
	cout<<a.substr(3,5)<<endl;
	
	return 0;
}
