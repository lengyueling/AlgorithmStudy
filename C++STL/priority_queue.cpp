#include <iostream>
#include <queue>
#include <ctime>
using namespace std;

//比较个位数
struct cmp
{
	bool operator()(int a, int b)
	{
		return a % 10 < b % 10;
	}
};

int main()
{
	//容器7:priorty_queue 优先队列(堆)
	//自动排序,默认从大到小,使用大根堆实现,vector为默认的存放容器
	//最大堆
	srand(time(NULL));
	priority_queue<int> pq;
	for (int i = 0; i < 10; i++)
	{
		int num = rand() % 100;
		pq.push(num);
		cout << "insert " << num << " in priorty queue" << endl;
	}
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl << endl;

	//最小堆
	priority_queue<int, vector<int>, greater<>> pq2;
	for (int i = 0; i < 10; i++)
	{
		int num = rand() % 100;
		pq2.push(num);
		cout << "insert " << num << " in priorty queue" << endl;
	}
	while (!pq2.empty())
	{
		cout << pq2.top() << " ";
		pq2.pop();
	}
	cout << endl << endl;

	//自定义
	priority_queue<int, vector<int>, cmp> pq3;
	for (int i = 0; i < 10; i++)
	{
		int num = rand() % 100;
		pq3.push(num);
		cout << "insert " << num << " in priorty queue" << endl;
	}
	while (!pq3.empty())
	{
		cout << pq3.top() << " ";
		pq3.pop();
	}
	return 0;
}

void test()
{
	priority_queue<int, vector<int>, less<>> q;
	//类似小根堆
	priority_queue<int, vector<int>, greater<>> q1;
	int n, t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		q.push(t);
	}
	while (q.size())
	{
		cout << q.top() << endl;
		q.pop();
	}
}
