#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

//稀疏图-邻接表
class SparseGraph
{
	private:
		int n, m;       // 节点数和边数
		bool directed;  // 是否为有向图
		vector<vector<int>> g;  // 图的具体数据
	public:
		//构造函数
		SparseGraph(int n, bool directed )
		{
			assert(n >= 0 );
			this->n = n;
			this->m = 0;    // 初始化没有任何边
			this->directed = directed;
			//g初始化为n个空的vector, 表示每一个g[i]都为空, 即没有任何边
			for (int i = 0; i < n; i++)
			{
				g.push_back(vector<int>());
			}
		}

		~SparseGraph()
		{

		}

		//返回节点个数
		int V()
		{
			return n;
		}

		//返回边的个数
		int E()
		{
			return m;
		}

		//向图中添加一个边
		void AddEdge(int v, int w )
		{
			assert(v >= 0 && v <= n);
			assert(w >= 0 && w <= n);
			g[v].push_back(w);
			//一般会允许有平行边（因为hasedge O(n)的时间复杂度比较高）
			//v != w解决自环边问题
			if (v != w && !directed)
			{
				g[w].push_back((v));
			}
			m++;
		}

		//验证图中是否有从v到w的边
		//O(n)的时间复杂度
		bool HasEdge(int v, int w )
		{
			assert(v >= 0 && v <= n);
			assert(w >= 0 && w <= n);
			for (int i = 0; i < g[v].size(); i++)
			{
				if (g[v][i] == w)
				{
					return true;
				}
			}
			return false;
		}
		// 显示图的信息
		void Show()
		{
			for(int i = 0 ; i < n ; i ++ )
			{
				cout << "vertex " << i << ":\t";
				for (int j = 0 ; j < g[i].size() ; j ++ )
				{
					cout << g[i][j] << "\t";
				}
				cout << endl;
			}
		}

		//邻边迭代器, 传入一个图和一个顶点,
		//迭代在这个图中和这个顶点相连的所有顶点
		//因为把图的结点公开不安全，所以使用这种方法来遍历图
		class AdjIterator
		{
			private:
				SparseGraph &G; //图G的引用
				int v;//传入的结点
				int index;//当前与传入结点的相连结点位置

			public:
				// 构造函数
				AdjIterator(SparseGraph &graph, int v): G(graph)
				{
					this->v = v;
					this->index = 0;
				}

				~AdjIterator()
				{

				}

				//返回图G中与顶点v相连接的第一个顶点
				int Begin()
				{
					index = 0;
					if (G.g[v].size())
					{
						return G.g[v][index];
					}
					//若没有顶点和v相连接, 则返回-1
					return -1;
				}

				//返回图G中与顶点v相连接的下一个顶点
				int Next()
				{
					index ++;
					if (index < G.g[v].size())
					{
						return G.g[v][index];
					}
					// 若没有顶点和v相连接, 则返回-1
					return -1;
				}

				//查看是否已经迭代完了图G中与顶点v相连接的所有顶点
				bool End()
				{
					return index >= G.g[v].size();
				}
		};
};
