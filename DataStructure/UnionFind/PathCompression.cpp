#include <iostream>
#include <cassert>
using namespace std;
class UnionFind
{
private:
	//使用一个数组构建一棵指向父节点的树
	//parent[i]表示第i个元素所指向的父节点
	int* parent;
	//rank[i]表示以i为根的集合所表示的树的层数
	int* rank;
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
		//路径压缩算法，优化方法1：
//		while (parent[p] != p)
//		{
//			//路径压缩算法，让元素p的父亲指向父亲的父亲
//			//因为根节点指向自己所以就算父亲的父亲不存在也没关系
//			parent[p] = parent[parent[p]];
//			p = parent[p];
//		}
//		return p;
		//路径压缩算法，优化方法2（递归）：
		//让所有的元素都指向对应集合的根节点
		//理论上性能会比第一种路径压缩算法效果好
		//但是递归比较消耗性能所以可能比第一种优化方法效果要差
		if( p != parent[p] )
		{
		    parent[p] = Find(parent[p]);
		}
		return parent[p];
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
		if(rank[pRoot] < rank[qRoot])
		{
			parent[pRoot] = qRoot;
		}
		else if(rank[pRoot] > rank[qRoot])
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

//UF5虽然相对UF4进行有了优化, 但优化的地方出现的情况较少,
//所以性能更优表现的不明显, 甚至在一些数据下性能会更差
//经过一系列的优化，并查集的时间复杂度近乎O(1)
void TestUF5(int n )
{
	srand( time(NULL) );
	UnionFind uf = UnionFind(n);
	
	time_t startTime = clock();
	
	for ( int i = 0 ; i < n ; i ++ )
	{
		int a = rand() % n;
		int b = rand() % n;
		uf.UnionElements(a, b);
	}
	for (int i = 0 ; i < n ; i ++ )
	{
		int a = rand() % n;
		int b = rand() % n;
		uf.IsConnected(a, b);
	}
	time_t endTime = clock();
	cout << "UF4, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}

int main()
{
	int n = 1000000;
	TestUF5(n);
	return 0;
}

