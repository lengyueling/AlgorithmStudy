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
			//初始化, 每一个id[i]指向自己, 没有合并的元素
			for (int i = 0; i < n; i++)
			{
				id[i] = i;
			}
		}
		~UnionFind()
		{
			delete[] id;
		}
		
		//找到对应的id值
		int Find(int p)
		{
			assert(p >= 0 && p < count);
			return id[p];
		}
		//p和q对应的id一样说明属于一个集合
		//O(1)的时间复杂度
		bool IsConnected(int p, int q)
		{
			return Find(p) == Find(q);
		}
		
		// 合并元素p和元素q所属的集合
		// O(n)的时间复杂度
		void UnionElements(int p, int q)
		{
			int pId = Find(p);
			int qId = Find(q);
			if (pId == qId)
			{
				return;
			}
			//O(n)时间复杂度
			//合并过程需要遍历一遍所有元素, 将两个元素的所属集合编号合并
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

