#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include "Edge.h"
#include "IndexMinHeap.h"
using namespace std;

//Dijkstra算法求最短路径
//时间复杂度为O(ElogV)
//无法处理负权边,要想处理要使用ford算法
template<typename Graph, typename Weight>
class Dijkstra
{
	private:
		Graph &G;                   //图的引用
		int s;                      //起始点
		Weight *distTo;             //distTo[i]存储从起始点s到i的最短路径长度
		bool *marked;               //标记数组, 在算法运行过程中标记节点i是否被访问
		vector<Edge<Weight>*> from; //from[i]记录最短路径中,到达i点的边是哪一条
	public:
		//构造函数,使用Dijkstra算法求最短路径
		Dijkstra(Graph &graph, int s): G(graph)
		{
			//算法初始化
			assert( s >= 0 && s < G.V() );
			this->s = s;
			distTo = new Weight[G.V()];
			marked = new bool[G.V()];
			for (int i = 0 ; i < G.V() ; i ++)
			{
				distTo[i] = Weight();
				marked[i] = false;
				from.push_back(NULL);
			}

			//使用索引堆记录当前找到的到达每个顶点的最短距离
			IndexMinHeap<Weight> ipq(G.V());
			
			//Dijkstra
			
			//对于起始点s进行初始化
			distTo[s] = Weight();
			from[s] = new Edge<Weight>(s, s, Weight());
			ipq.Insert(s, distTo[s]);
			marked[s] = true;
		
			
			while(!ipq.IsEmpty())
			{
				int v = ipq.ExtractMinIndex();
				//disTo[v]存放的就是s到v的当前最短距离
				marked[v] = true;
				//松弛操作Relaxation
				typename Graph::AdjIterator adj(G, v);
				for(Edge<Weight>* e = adj.Begin(); !adj.End(); e = adj.Next())
				{
					int w = e->Other(v);
					if(!marked[w])
					{
						if(from[w] == NULL || distTo[v] + e->WT() < distTo[w])
						{
							distTo[w] = distTo[v] + e->WT();
							from[w] = e;
							if(ipq.Contain(w))
							{
								ipq.Change(w, distTo[w]);
							}
							else
							{
								ipq.Insert(w, distTo[w]);
							}
						}
					}
				}
			}
			
		}

		// 析构函数
		~Dijkstra()
		{
			delete[] distTo;
			delete[] marked;
			delete from[s];
		}

		// 返回从s点到w点的最短路径长度
		Weight ShortestPathTo(int w)
		{
			assert(w >= 0 && w < G.V());
			assert(HasPathTo(w));
			return distTo[w];
		}

		//判断从s点到w点是否联通
		bool HasPathTo(int w)
		{
			assert(w >= 0 && w < G.V());
			return marked[w];
		}

		//寻找从s到w的最短路径,将整个路径经过的边存放在vec中
		void ShortestPath(int w, vector<Edge<Weight>> &vec)
		{
			assert(w >= 0 && w < G.V());
			assert(HasPathTo(w));

			// 通过from数组逆向查找到从s到w的路径, 存放到栈中
			stack<Edge<Weight>*> s;
			Edge<Weight> *e = from[w];
			while ( e->V() != this->s )
			{
				s.push(e);
				e = from[e->V()];
			}
			s.push(e);

			//从栈中依次取出元素,获得顺序的从s到w的路径
			while (!s.empty())
			{
				e = s.top();
				vec.push_back(*e);
				s.pop();
			}
		}

		//打印出从s点到w点的路径
		void ShowPath(int w)
		{
			assert(w >= 0 && w < G.V());
			assert(HasPathTo(w));

			vector<Edge<Weight>> vec;
			ShortestPath(w, vec);
			for (int i = 0 ; i < vec.size() ; i ++)
			{
				cout<<vec[i].V()<<" -> ";
				if (i == vec.size() - 1)
				{
					cout<<vec[i].W()<<endl;
				}
			}	
		}
};
#endif
