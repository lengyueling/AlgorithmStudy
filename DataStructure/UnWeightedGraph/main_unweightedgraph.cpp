#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
using namespace std;

int main() 
{
	int N = 20;
	int M = 100;
	srand( time(NULL) );
	//Sparse Graph
	SparseGraph g1(N, false);
	for (int i = 0 ; i < M ; i ++)
	{
		int a = rand() % N;
		int b = rand() % N;
		g1.AddEdge( a, b );
	}
	//O(E)
	for (int v = 0 ; v < N ; v ++)
	{
		cout << v << " : ";
		SparseGraph::AdjIterator adj(g1, v );
		for (int w = adj.Begin() ; !adj.End() ; w = adj.Next())
		{
			cout << w << " ";
		}
		cout << endl;
	}
	
	cout<<"---------------------------"<<endl;
	
	//Dense Graph
	DenseGraph g2(N, false);
	for ( int i = 0 ; i < M ; i ++ )
	{
		int a = rand() % N;
		int b = rand() % N;
		g2.AddEdge( a, b );
	}
	
	//O(V^2)
	for (int v = 0 ; v < N ; v ++ )
	{
		cout << v << " : ";
		DenseGraph::AdjIterator adj( g2, v );
		for (int w = adj.Begin() ; !adj.End() ; w = adj.Next())
		{
			cout << w << " ";
		}
		cout << endl;
	}
    return 0;
}
