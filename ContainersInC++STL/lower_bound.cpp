#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	//用的是二分查找的方法
	//区间是前闭后开
	//返回>=key的值 需要是一个有序数组
	//找不到的话会返回vec.end() 或者比数组范围更大1的位置
	int a[] = {1,2,3,4,5,6};
	int t = lower_bound(a, a+6, 200) - a;
	cout<<t<<endl;
	vector<int> vec = {1,2,3,4,5,6};
	int s = lower_bound(vec.begin(),vec.end(),10) - vec.begin();
	cout<<s<<endl;
	
	return 0;
}
