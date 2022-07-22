#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Components.h"
#include "Path.h"
#include "ShortestPath.h"
using namespace std;

int main() 
{
	string filename = "testG2.txt";
	SparseGraph g = SparseGraph(6, false);
	ReadGraph<SparseGraph> readGraph(g, filename);
	g.Show();
	cout<<endl;
	
	//图的DFS
	//稀疏图（邻接表）：O(V+E)
	//稠密图（邻接矩阵）：O(v^2)
	Path<SparseGraph> dfs(g,0);
	cout<<"DFS: " << endl;
	dfs.ShowPath(4);
	
	//图的BFS
	//稀疏图（邻接表）：O(V+E)
	//稠密图（邻接矩阵）：O(v^2)
	ShortestPath<SparseGraph> bfs(g,0);
	cout<<"BFS: " << endl;
	bfs.ShowPath(4);
    return 0;
}
