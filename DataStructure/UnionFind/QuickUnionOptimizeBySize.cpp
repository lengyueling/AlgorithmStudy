#include <iostream>
#include <cassert>
using namespace std;
class UnionFind
{
private:
	//使用一个数组构建一棵指向父节点的树
	//parent[i]表示第i个元素所指向的父节点
	int* parent;
	//sz[i]表示以i为根的集合中元素个数
	int* sz;
	int count;
public:
	UnionFind(int count)
	{
		this->count = count;
		parent = new int [count];
		sz = new int [count];
		//初始化, 每一个parent[i]指向自己, 表示每一个元素自己自成一个集合
		for (int i = 0; i < count; i++)
		{
			parent[i] = i;
			sz[i] = 1;
		}
	}
	~UnionFind()
	{
		delete[] parent;
		delete[] sz;
	}
	
	//查找过程, 查找元素p所对应的集合编号
	//O(h)复杂度, h为树的高度
	int Find(int p)
	{
		assert(p >= 0 && p < count);
		while (parent[p] != p)
		{
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
		if(sz[pRoot] < sz[qRoot])
		{
			parent[pRoot] = qRoot;
			sz[qRoot] += sz[pRoot];
		}
		else
		{
			parent[qRoot] = pRoot;
			sz[pRoot] += sz[pRoot];
		}
		
	}
};

void TestUF3( int n )
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
	
	cout << "UF3, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}

int main()
{
	int n = 100000;
	TestUF3(n);
	return 0;
}

