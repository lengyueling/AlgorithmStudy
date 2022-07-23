#include <iostream>
#include <iomanip>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "LazyPrimMST.h"
#include "PrimMST.h"
#include "KruskalMST.h"
using namespace std;

int main() 
{
	//Test Lazy Prim MST
	string filename = "testG1.txt";
	int V = 8;
	
	DenseGraph<double> g = DenseGraph<double>(V, false);
	ReadGraph<DenseGraph<double>, double> readGraph(g, filename);
	
	cout<<"Test Lazy Prim MST:"<<endl;
	LazyPrimMST<DenseGraph<double>, double> lazyPrimMST(g);
	vector<Edge<double>> mst = lazyPrimMST.MSTEdges();
	for( int i = 0 ; i < mst.size() ; i ++ )
	{
		cout<<mst[i]<<endl;
	}
	cout<<"The MST weight is: "<<lazyPrimMST.Result()<<endl;
	
	cout<<"-----------------------------"<<endl;
	
	// Test Prim MST
	cout<<"Test Prim MST:"<<endl;
	PrimMST<DenseGraph<double>, double> primMST(g);
	mst = primMST.MSTEdges();
	for( int i = 0; i < mst.size(); i++)
	{
		cout<<mst[i]<<endl;
	}
	cout<<"The MST weight is: "<<primMST.Result()<<endl;
	
	cout<<"-----------------------------"<<endl;
	
	// Test Kruskal MST
	cout<<"Test Kruskal MST:"<<endl;
	KruskalMST<DenseGraph<double>, double> kruskalMST(g);
	mst = kruskalMST.MSTEdges();
	for(int i = 0; i < mst.size(); i++)
	{
		cout<<mst[i]<<endl;
	}
	cout<<"The MST weight is: "<<kruskalMST.Result()<<endl;

	return 0;
}
