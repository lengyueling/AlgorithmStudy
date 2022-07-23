#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Dijkstra.h"

using namespace std;

//测试Dijkstra最短路径算法
int main()
{

	string filename = "testG2.txt";
	int V = 5;
	//Dijkstra最短路径算法同时适用于有向图和无向图
	SparseGraph<int> g = SparseGraph<int>(V, true);
	//SparseGraph<int> g = SparseGraph<int>(V, false);
	ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

	cout<<"Test Dijkstra:"<<endl;
	Dijkstra<SparseGraph<int>, int> dij(g, 0);
	for (int i = 1; i < V;i++)
	{
		if (dij.HasPathTo(i))
		{
			cout<<"Shortest Path to "<<i<<" : "<< dij.ShortestPathTo(i)<<endl;
			dij.ShowPath(i);
		}
		else
		{
			cout<<"No Path to " << i << endl;
		}
		cout<<"----------" <<endl;
	}

	return 0;
}
