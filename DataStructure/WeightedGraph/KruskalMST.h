#ifndef KRUSKAL_MST_H
#define KRUSKAL_MST_H

#include <iostream>
#include <vector>
#include "MinHeap.h"
#include "UnionFind.h"
#include "Edge.h"
using namespace std;

//Kruskal算法
//时间复杂度O(ElogE)
template <typename Graph, typename Weight>
class KruskalMST{

private:
    vector<Edge<Weight>> mst;   //最小生成树所包含的所有边
    Weight mstWeight;           //最小生成树的权值

public:
    //构造函数,使用Kruskal算法计算graph的最小生成树
    KruskalMST(Graph &graph)
	{
		MinHeap<Edge<Weight>> pq(graph.E());
		for(int i = 0; i < graph.V(); i++)
		{
			typename Graph::AdjIterator adj(graph,i);
			for(Edge<Weight> *e = adj.Begin(); !adj.End(); e = adj.Next())
			{
				if(e->V() < e->W())
				{
					pq.Insert(*e);
				}
			}
		}
		
		
		UnionFind uf(graph.V());
		while(!pq.IsEmpty() && mst.size() < graph.V()-1)
		{
			//从最小堆中依次从小到大取出所有的边
			Edge<Weight> e = pq.ExtractMin();
			//如果该边的两个端点是联通的,说明加入这条边将产生环,扔掉这条边
			if(uf.IsConnected(e.V(), e.W()))
			{
				continue;
			}
			//否则,将这条边添加进最小生成树,同时标记边的两个端点联通
			mst.push_back(e);
			uf.UnionElements(e.V(), e.W());
		}
		
		mstWeight = mst[0].WT();
		for(int i = 1; i < mst.size(); i++)
		{
			mstWeight += mst[i].WT();
		}
    }

    ~KruskalMST()
	{ 
		
	}

    //返回最小生成树的所有边
    vector<Edge<Weight>> MSTEdges()
	{
        return mst;
    };

    //返回最小生成树的权值
    Weight Result()
	{
        return mstWeight;
    };
};

#endif
