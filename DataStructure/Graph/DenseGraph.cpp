#include <iostream>
#include <vector>
#include <cassert>
#include "ReadGraph.h"
using namespace std;

//稠密图-邻接矩阵
class DenseGraph
{
	private:
		//节点数和边数
		int n, m;
		//是否为有向图
		bool directed;
		//图的具体数据(邻接矩阵)
		vector<vector<bool>> g;

	public:
		DenseGraph(int n, bool directed)
		{
			this->n = n;
			this->m = 0;
			this->directed = directed;
			//g初始化为n*n的布尔矩阵, 每一个g[i][j]均为false, 表示没有任和边
			for (int i = 0; i < n; i++)
			{
				//vector<bool>(n, false)创建了n个元素，每个元素都是false
				g.push_back(vector<bool>(n, false));
			}
		}
		~DenseGraph()
		{

		}

		//返回目前的顶点数
		int V()
		{
			return n;
		}
		//返回现在的边数
		int E()
		{
			return m;
		}
		//向图中添加一个边
		void AddEdge(int v, int w)
		{
			assert(v >= 0 && v <= n);
			assert(w >= 0 && w <= n);
			//已经有边了就不能再添加
			if (HasEdge(v, w))
			{
				return;
			}

			g[v][w] = true;
			if (!directed)
			{
				g[w][v] = true;
			}
			m++;
		}

		//验证图中是否有从v到w的边
		bool HasEdge( int v, int w )
		{
			assert(v >= 0 && v <= n);
			assert(w >= 0 && w <= n);
			return g[v][w];
		}

		// 显示图的信息
		void Show()
		{
			for ( int i = 0 ; i < n ; i ++ )
			{
				for ( int j = 0 ; j < n ; j ++ )
				{
					cout << g[i][j] << "\t";
				}	
				cout << endl;
			}
		}

		//邻边迭代器, 传入一个图和一个顶点,
		//迭代在这个图中和这个顶点向连的所有顶点
		//因为把图的结点公开不安全，所以使用这种方法来遍历图
		class AdjIterator
		{
			private:
				DenseGraph &G;  //图G的引用
				int v;//传入的结点
				int index;//当前与传入结点的相连结点位置

			public:
				AdjIterator(DenseGraph &graph, int v): G(graph)
				{
					assert( v >= 0 && v < G.n );
					this->v = v;
					this->index = -1;   //索引从-1开始, 因为每次遍历都需要调用一次next()
				}

				~AdjIterator()
				{

				}

				//返回图G中与顶点v相连接的第一个顶点
				int Begin()
				{
					//索引从-1开始, 因为每次遍历都需要调用一次next()
					index = -1;
					return Next();
				}

				//返回图G中与顶点v相连接的下一个顶点
				int Next()
				{

					//从当前index开始向后搜索, 直到找到一个g[v][index]为true的结点
					for (index += 1 ; index < G.V(); index++)
					{
						if (G.g[v][index] )
						{
							return index;
						}
					}
					//若没有顶点和v相连接, 则返回-1
					return -1;
				}

				//查看是否已经迭代完了图G中与顶点v相连接的所有顶点
				bool End()
				{
					return index >= G.V();
				}
		};
};

int main()
{
	int N = 20;
	int M = 100;
	srand(time(NULL));
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
	
	cout << "---------------------------" << endl;
	string filename = "testG1.txt";
	DenseGraph testG1( 13, false );
	ReadGraph<DenseGraph> readGraph1(testG1, filename );
	cout << "test G1 in Sparse Graph:" << endl;
	testG1.Show();
	
	cout << "---------------------------" << endl;
	filename = "testG2.txt";
	DenseGraph testG2( 6 , false );
	ReadGraph<DenseGraph> readGraph2( testG2 , filename );
	cout<<"test G2 in Sparse Graph:" << endl;
	testG2.Show();
	return 0;
}

