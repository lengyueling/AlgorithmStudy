#include <vector>
#include <stack>
#include <iostream>
#include <cassert>
#include <queue>
using namespace std;

//路径查询
template <typename Graph>
class ShortestPath
{
private:
	Graph &G;		//图的引用
	int s;			//起始点
	bool *visited;	//记录dfs的过程中节点是否被访问
	int *from;		//记录路径, from[i]表示查找的路径上i的上一个节点
	int *ord;		//记录最短距离,ord[i]表示s到各个结点的最短距离
	
	void BFS(int s)
	{
		queue<int> q;
		q.push(s);
		visited[s] = true;
		while(!q.empty())
		{
			int v = q.front();
			q.pop();
			typename Graph::AdjIterator adj(G, v);
			for(int i = adj.Begin(); !adj.End(); i = adj.Next())
			{
				if(!visited[i])
				{
					q.push(i);
					visited[i] = true;
					from[i] = v;
					ord[i] = ord[v] + 1;
				}
			}
		}
	}
	
public:
	ShortestPath(Graph &graph, int s):G(graph)
	{
		//算法初始化
		assert(s >= 0 && s < G.V());
		visited = new bool[G.V()];
		from = new int[G.V()];
		ord = new int[G.V()];
		for(int i = 0; i < G.V(); i++)
		{
			visited[i] = false;
			from[i] = -1;
			ord[i] = -1;
		}
		this->s = s;
		//最短路径算法 (BFS)
		BFS(s);
	}
	~ShortestPath()
	{
		delete[] visited;
		delete[] from;
		delete[] ord;
	}
	
	bool HasPath(int w)
	{
		assert(w >= 0 && w < G.V());
		return visited[w];
	}
	
	void ThePath(int w, vector<int> &vec)
	{
		stack<int> s;
		//通过from数组逆向查找到从s到w的路径, 存放到栈中
		int p = w;
		while(p != -1)
		{
			s.push(p);
			p = from[p];
		}
		//从栈中依次取出元素, 获得顺序的从s到w的路径
		vec.clear();
		while(!s.empty())
		{
			vec.push_back(s.top());
			s.pop();
		}
	}
	
	void ShowPath(int w)
	{
		vector<int> vec;
		ThePath(w, vec);
		for(int i = 0; i < vec.size(); i++)
		{
			cout<<vec[i];
			if(i == vec.size()-1)
			{
				cout<<endl;
			}
			else
			{
				cout<<"->";
			}
		}
	}
	
	//查询s到w的最短路径长度
	int Length(int w)
	{
		assert(w>=0 && w < G.V());
		return ord[w];
	}
};

