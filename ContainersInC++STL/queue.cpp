#include <iostream>
#include <queue>

using namespace std;
int main()
{
	//容器5:queue(先进先出)
//	queue<int> q;
//	int n,t;
//	cin>>n;
//	for(int i = 0; i < n; i++)
//	{
//		cin>>t;
//		q.push(t);
//	}
//	while(q.size())
//	{
//		//返回队头元素和队尾元素
//		cout<<q.front()<<" "<<q.back()<<endl;
//		q.pop();
//	}
	//数组模拟queue
	int z[100];
	int n, t;
	int hh = 0, tt = 0;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>t;
		z[tt++] = t;
	}
	while(hh < tt)
	{
		cout<<z[hh++]<<endl;
	}
	
	return 0;
}
