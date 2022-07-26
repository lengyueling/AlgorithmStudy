#include <iostream>
#include <stack>
using namespace std;
int main()
{
	//容器7:deque 双端队列
	deque <int> q;
	int t = 0;
	q.push_back(t);
	q.push_front(t);
	q.pop_back();
	q.pop_front();
	return 0;
}
