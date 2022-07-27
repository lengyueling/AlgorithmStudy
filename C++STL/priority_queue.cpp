#include <iostream>
#include <queue>
using namespace std;
int main()
{
	//容器7:priorty_queue 优先队列(堆)
	//自动排序,从大到小,类似于大根堆,vector为默认的存放容器
	priority_queue<int, vector<int>, less<>> q; 
	//类似小根堆
	priority_queue<int, vector<int>, greater<>> q1; 
	int n, t;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>t;
		q.push(t);
	}
	while(q.size())
	{
		cout<<q.top()<<endl;
		q.pop();
	}
	return 0;
}
