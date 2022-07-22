#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Components.h"
#include "Path.h"
using namespace std;
//图的DFS
//稀疏图（邻接表）：O(V+E)
//稠密图（邻接矩阵）：O(v^2)
int main() 
{
	string filename = "testG2.txt";
	SparseGraph g = SparseGraph(6, false);
	ReadGraph<SparseGraph> readGraph(g, filename);
	g.Show();
	cout<<endl;
	
	Path<SparseGraph> path(g,0);
	cout<<"Path from 0 to 4 : " << endl;
	path.ShowPath(4);
    return 0;
}
