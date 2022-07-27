#include <iostream>
#include <stack>
using namespace std;
int main()
{
	//容器4:stack(先进后出)
	stack<int> sta;
	int n, t;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>t;
		//入栈
		sta.push(t);
	}
	cout<<sta.top()<<endl;
	//出栈
	sta.pop();
	cout<<sta.top()<<endl;
	
	//用数组模拟栈，输出后可以保留栈的数据
//	int z[100];
//	int n,t;
//	int tt = 0;
//	cin>>n;
//	//模拟进栈
//	for(int i = 0; i < n; i++)
//	{
//		cin>>t;
//		z[tt++] = t;
//	}
//	//模拟出栈（不会真的出栈）
//	for(int i = tt - 1; i >= 0; i--)
//	{
//		cout<<z[i]<<endl;
//	}
	
	return 0;
}
