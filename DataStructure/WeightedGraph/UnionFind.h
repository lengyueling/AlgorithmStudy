#ifndef UNION_FIND_H
#define UNION_FIND_H
#include <iostream>
#include <cassert>
using namespace std;
class UnionFind
{
	private:
		//使用一个数组构建一棵指向父节点的树

		//rank[i]表示以i为根的集合所表示的树的层数
		int* rank;
		//parent[i]表示第i个元素所指向的父节点
		int* parent;
		int count;
	public:
		UnionFind(int count)
		{
			this->count = count;
			parent = new int [count];
			rank = new int [count];
			//初始化, 每一个parent[i]指向自己, 表示每一个元素自己自成一个集合
			for (int i = 0; i < count; i++)
			{
				parent[i] = i;
				rank[i] = 1;
			}
		}
		~UnionFind()
		{
			delete[] parent;
			delete[] rank;
		}

		//查找过程, 查找元素p所对应的集合编号
		//O(h)复杂度, h为树的高度
		int Find(int p)
		{
			assert(p >= 0 && p < count);
			while (p != parent[p])
			{
				parent[p] = parent[parent[p]];
				p = parent[p];
			}
			return p;
		}

		//查看元素p和元素q是否所属一个集合
		//O(h)复杂度, h为树的高度
		bool IsConnected(int p, int q)
		{
			return Find(p) == Find(q);
		}

		//合并元素p和元素q所属的集合
		//O(h)复杂度, h为树的高度
		void UnionElements(int p, int q)
		{
			int pRoot = Find(p);
			int qRoot = Find(q);
			if (pRoot == qRoot)
			{
				return;
			}
			//根据两个元素所在树的层数不同判断合并方向
			//将层数少的集合合并到层数多的集合上
			//当两个元素的层数一样时候，无论是谁合并到谁身上都可以，同时层数+1
			if (rank[pRoot] < rank[qRoot])
			{
				parent[pRoot] = qRoot;
			}
			else if (rank[qRoot] < rank[pRoot])
			{
				parent[qRoot] = pRoot;
			}
			else//rank[pRoot] == rank[qRoot]
			{
				parent[pRoot] = qRoot;
				rank[qRoot] += 1;   //此时维护rank的值
			}
		}
};
#endif
