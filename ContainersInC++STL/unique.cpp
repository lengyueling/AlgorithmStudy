#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> vec = {3,3,4,4,5,5,6,7,7,4};
	sort(vec.begin(), vec.end());
	for(auto j : vec)
	{
		cout<<j<<" ";
	}
	cout<<endl;
	//将重复的数字堆在数组有序数组后面
	//返回重复的第一个元素
	//通过erase删除后面重复的元素
	vec.erase(unique(vec.begin(), vec.end()),vec.end());
	for(auto j : vec)
	{
		cout<<j<<" ";
	}
	
	cout<<endl;
	//对数组进行去重
	int a[200] = {0,1,2,2,2,3,0,5,7,1};
	sort(a, a+10);
	int n = unique(a, a+10) - a;
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}


