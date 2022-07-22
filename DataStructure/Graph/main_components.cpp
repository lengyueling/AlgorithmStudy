#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Components.h"
using namespace std;

int main() 
{
	//测试图的联通分量算法
	// TestG1.txt - g1 and g2
	string filename1 = "testG1.txt";
	SparseGraph g31 = SparseGraph(13, false);
	ReadGraph<SparseGraph> readGraph31(g31, filename1);
	Component<SparseGraph> component1(g31);
	cout<<"TestG1.txt, Using Sparse Graph, Component Count: "<<component1.Count()<<endl;
	
	DenseGraph g32 = DenseGraph(13, false);
	ReadGraph<DenseGraph> readGraph32(g32, filename1);
	Component<DenseGraph> component2(g32);
	cout<<"TestG1.txt, Using Dense Graph, Component Count: "<<component2.Count()<<endl;
	
	cout<<"---------------------------"<<endl;
	
	// TestG2.txt - g3 and g4
	string filename2 = "testG2.txt";
	SparseGraph g41 = SparseGraph(6, false);
	ReadGraph<SparseGraph> readGraph33(g41, filename2);
	Component<SparseGraph> component3(g41);
	cout<<"TestG2.txt, Using Sparse Graph, Component Count: "<<component3.Count()<<endl;
	
	DenseGraph g42 = DenseGraph(6, false);
	ReadGraph<DenseGraph> readGraph34(g42, filename2);
	Component<DenseGraph> component4(g42);
	cout<<"TestG2.txt, Using Dense Graph, Component Count: "<<component4.Count()<<endl;

    return 0;
}
