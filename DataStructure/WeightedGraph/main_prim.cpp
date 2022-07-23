#include <iostream>
#include <iomanip>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "LazyPrimMST.h"
#include "PrimMST.h"
using namespace std;

//Test Lazy Prim MST
int main() 
{
	string filename = "testG1.txt";
	int V = 8;
	
	SparseGraph<double> g = SparseGraph<double>(V, false);
	ReadGraph<SparseGraph<double>, double> readGraph(g, filename);
	
	cout<<"Test Lazy Prim MST:"<<endl;
	LazyPrimMST<SparseGraph<double>, double> lazyPrimMST(g);
	vector<Edge<double>> mst = lazyPrimMST.MSTEdges();
	for( int i = 0 ; i < mst.size() ; i ++ )
	{
		cout<<mst[i]<<endl;
	}
	cout<<"The MST weight is: "<<lazyPrimMST.Result()<<endl;
	
	cout<<"-----------------------------"<<endl;
	
	// Test Prim MST
	cout<<"Test Prim MST:"<<endl;
	PrimMST<SparseGraph<double>, double> primMST(g);
	mst = primMST.MSTEdges();
	for( int i = 0 ; i < mst.size() ; i ++ )
	{
		cout<<mst[i]<<endl;
	}
	cout<<"The MST weight is: "<<primMST.Result()<<endl;
	
	return 0;
}
