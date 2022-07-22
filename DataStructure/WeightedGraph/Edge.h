#ifndef _EDGE_H_
#define _EDGE_H_

#include <vector>
#include <stack>
#include <iostream>
#include <cassert>
using namespace std;

template<typename Weight>
class Edge
{
	private:
		//边的两个端点
		int a, b;
		//边的权值
		Weight weight;
	public:
		Edge(int a, int b, Weight weight)
		{
			this->a = a;
			this->b = b;
			this->weight = weight;
		}
		Edge()
		{

		}
		~Edge()
		{

		}

		//返回第一个顶点
		int V()
		{
			return a;
		}

		//返回第二个顶点
		int W()
		{
			return b;
		}

		//返回权值
		Weight WT()
		{
			return weight;
		}

		//给定一个顶点, 返回另一个顶点
		int Other(int x)
		{
			assert(x == a || x == b);
			return x == a ? b : a;
		}

		//输出边的信息(运用friend重载 <<)
		friend ostream& operator<<(ostream &os, const Edge &e)
		{
			os << e.a << "-" << e.b << ": " << e.weight;
			return os;
		}

		//边的大小比较, 是对边的权值的大小比较
		bool operator<(Edge<Weight>& e)
		{
			return weight < e.wt();
		}
		bool operator<=(Edge<Weight>& e)
		{
			return weight <= e.wt();
		}
		bool operator>(Edge<Weight>& e)
		{
			return weight > e.wt();
		}
		bool operator>=(Edge<Weight>& e)
		{
			return weight >= e.wt();
		}
		bool operator==(Edge<Weight>& e)
		{
			return weight == e.wt();
		}
};
#endif
