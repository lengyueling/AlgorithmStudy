#include <vector>
#include <stack>
#include <iostream>
#include <cassert>
using namespace std;

//路径查询
template <typename Graph>
class Path
{
private:
	Graph &G;		//图的引用
	int s;			//起始点
	bool *visited;	//记录dfs的过程中节点是否被访问
	int *from;		//记录路径, from[i]表示查找的路径上i的上一个节点
	
	// 图的深度优先遍历
	void DFS(int v)
	{
		visited[v] = true;
		typename Graph::AdjIterator adj(G,v);
		for(int i = adj.Begin(); !adj.End(); i = adj.Next())
		{
			if(!visited[i])
			{
				from[i] = v;
				DFS(i);
			}
		}
	}
public:
	Path(Graph &graph, int s):G(graph)
	{
		//算法初始化
		assert(s >= 0 && s < G.V());
		visited = new bool[G.V()];
		from = new int[G.V()];
		for(int i = 0; i < G.V(); i++)
		{
			visited[i] = false;
			from[i] = -1;
		}
		this->s = s;
		//寻路算法（通过DFS虽然不一定得到的是最短路径，但是可以得到一条路径）
		DFS(s);
	}
	~Path()
	{
		delete[] visited;
		delete[] from;
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
};

