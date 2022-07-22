#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
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
	
	cout<<"---------------------------"<<endl;
	
	//使用两种图的存储方式读取testG1.txt文件
	string filename = "testG1.txt";
	SparseGraph g11( 13 , false );
	ReadGraph<SparseGraph> readGraph1( g11 , filename );
	cout<<"test G1 in Sparse Graph:" << endl;
	g11.Show();
	
	cout<<"---------------------------"<<endl;
	
	DenseGraph g12( 13 , false );
	ReadGraph<DenseGraph> readGraph2( g12 , filename );
	cout<<"test G1 in Dense Graph:" << endl;
	g12.Show();
	
	cout<<"---------------------------"<<endl;
	
	//使用两种图的存储方式读取testG2.txt文件
	filename = "testG2.txt";
	SparseGraph g21( 6 , false );
	ReadGraph<SparseGraph> readGraph3( g21 , filename );
	cout<<"test G2 in Sparse Graph:" << endl;
	g21.Show();
	
	cout<<"---------------------------"<<endl;
	
	DenseGraph g22( 6 , false );
	ReadGraph<DenseGraph> readGraph4( g22 , filename );
	cout<<"test G2 in Dense Graph:" << endl;
	g22.Show();
    return 0;
}
