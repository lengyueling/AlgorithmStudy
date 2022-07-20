#include <iostream>
#include <cassert>
using namespace std;
class UnionFind
{
	private:
		//第二版Union-Find, 使用一个数组构建一棵指向父节点的树
		//parent[i]表示第i个元素所指向的父节点
		int* parent;
		int count;
	public:
		UnionFind(int n)
		{
			count = n;
			parent = new int [n];
			//初始化, 每一个parent[i]指向自己, 表示每一个元素自己自成一个集合
			for (int i = 0; i < count; i++)
			{
				parent[i] = i;
			}
		}
		~UnionFind()
		{
			delete[] parent;
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
			parent[pRoot] = qRoot;
		}
};

// 测试第二版本的并查集, 测试元素个数为n, 测试逻辑和之前是完全一样的
void TestUF2( int n )
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

	cout << "UF2, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}

int main()
{
	int n = 100000;
	TestUF2(n);
	return 0;
}

