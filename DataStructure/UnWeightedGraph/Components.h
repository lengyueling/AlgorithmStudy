#include <iostream>
#include <cassert>
using namespace std;

//求无权图的联通分量
template <typename Graph>
class Component
{
private:
	Graph &G;		//图的引用
	bool *visited;	//记录dfs的过程中节点是否被访问
	int ccount;		//记录联通分量个数
	int *id;		//每个节点所对应的联通分量的id
	
	void DFS(int v)
	{
		visited[v] = true;
		id[v] = ccount;
		typename Graph::AdjIterator adj(G, v);
		for(int i = adj.Begin(); !adj.End(); i = adj.Next())
		{
			if(!visited[i])
			{
				DFS(i);
			}
		}
	}
public:
	Component(Graph &graph): G(graph)
	{
		//初始化
		visited = new bool[G.V()];
		id = new int[G.V()];
		ccount = 0;
		for(int i = 0; i < G.V(); i++)
		{
			visited[i] = false;
			id[i] = -1;
		}
		
		//求图的联通分量
		for(int i = 0; i < G.V(); i++)
		{
			if(!visited[i])
			{
				DFS(i);
				ccount++;
			}
		}
	}
	~Component()
	{
		delete[] visited;
		delete[] id;
	}
	
	//返回图的联通分量个数
	int Count()
	{
		return ccount;
	}
	
	//查询点v和点w是否联通
	bool IsConnected(int v , int w)
	{
		assert(v >= 0 && v < G.V());
		assert(w >= 0 && w < G.V());
		return id[v] == id[w];
	}
};
