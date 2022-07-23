#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
using namespace std;

//稠密图-邻接矩阵
template<typename Weight>
class DenseGraph
{
	private:
		//节点数和边数
		int n, m;
		//是否为有向图
		bool directed;
		//图的具体数据(邻接矩阵)
		vector<vector<Edge<Weight>*>> g;

	public:
		DenseGraph(int n, bool directed)
		{
			assert( n >= 0 );
			this->n = n;
			this->m = 0;
			this->directed = directed;
			//g初始化为n*n的布尔矩阵, 每一个g[i][j]均为false, 表示没有任和边
			for (int i = 0; i < n; i++)
			{
				g.push_back(vector<Edge<Weight>*>(n, NULL));
			}
		}
		
		~DenseGraph()
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					if(g[i][j] != NULL)
					{
						delete g[i][j];
					}
				}
			}
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
		void AddEdge(int v, int w, Weight weight)
		{
			assert(v >= 0 && v <= n);
			assert(w >= 0 && w <= n);
			//已经有边了就不能再添加
			if (HasEdge(v, w))
			{
				delete g[v][w];
				if(v != w && !directed)
				{
					delete g[w][v];
				}
				m--;
			}

			g[v][w] = new Edge<Weight>(v, w, weight);
			if (v != w && !directed)
			{
				g[w][v] = new Edge<Weight>(w, v, weight);
			}
			m++;
		}

		//验证图中是否有从v到w的边
		bool HasEdge( int v, int w )
		{
			assert(v >= 0 && v <= n);
			assert(w >= 0 && w <= n);
			return g[v][w] != NULL;
		}

		// 显示图的信息
		void Show()
		{
			for ( int i = 0 ; i < n ; i ++ )
			{
				for ( int j = 0 ; j < n ; j ++ )
				{
					if(g[i][j])
					{
						cout<<g[i][j]->WT() << "\t";
					}
					else
					{
						cout<<"NULL\t";
					}
					
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
				int v;			//传入的结点
				int index;		//当前与传入结点的相连结点位置

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
				Edge<Weight>* Begin()
				{
					//索引从-1开始, 因为每次遍历都需要调用一次next()
					index = -1;
					return Next();
				}

				//返回图G中与顶点v相连接的下一个顶点
				Edge<Weight>* Next()
				{

					//从当前index开始向后搜索, 直到找到一个g[v][index]为true的结点
					for (index += 1 ; index < G.V(); index++)
					{
						if (G.g[v][index] )
						{
							return G.g[v][index];
						}
					}
					//若没有顶点和v相连接, 则返回NULL
					return NULL;
				}

				//查看是否已经迭代完了图G中与顶点v相连接的所有顶点
				bool End()
				{
					return index >= G.V();
				}
		};
};
