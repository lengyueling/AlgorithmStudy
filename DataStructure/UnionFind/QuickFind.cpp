#include <iostream>
#include <cassert>
using namespace std;
class UnionFind
{
	private:
		int* id;
		int count;
	public:
		UnionFind(int n)
		{
			count = n;
			id = new int [n];
			for (int i = 0; i < n; i++)
			{
				id[i] = i;
			}
		}
		~UnionFind()
		{
			delete[] id;
		}

		int Find(int p)
		{
			assert(p >= 0 && p < count);
			return id[p];
		}

		bool IsConnected(int p, int q)
		{
			return Find(p) == Find(q);
		}
		void UnionElements(int p, int q)
		{
			int pId = Find(p);
			int qId = Find(q);
			if (pId == qId)
			{
				return;
			}
			//O(n)时间复杂度
			for (int i = 0; i < count; i++)
			{
				if (id[p] == pId)
				{
					id[p] = qId;
				}
			}
		}
};

// 测试第一版本的并查集, 测试元素个数为n
void TestUF1( int n )
{
	srand( time(NULL) );
	UnionFind uf = UnionFind(n);

	time_t startTime = clock();

	// 进行n次操作, 每次随机选择两个元素进行合并操作
	for ( int i = 0 ; i < n ; i ++ )
	{
		int a = rand() % n;
		int b = rand() % n;
		uf.UnionElements(a, b);
	}
	// 再进行n次操作, 每次随机选择两个元素, 查询他们是否同属一个集合
	for (int i = 0 ; i < n ; i ++ )
	{
		int a = rand() % n;
		int b = rand() % n;
		uf.IsConnected(a, b);
	}
	time_t endTime = clock();

	// 打印输出对这2n个操作的耗时
	cout << "UF1, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}

int main()
{
	int n = 10000;
	TestUF1(n);
	return 0;
}

