#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

//有一个背包,容量为C,现在有n钟不同的物品编号为0..n-1,其中每一件物品的重量为w(i),价值为v(i)
//问可以向这个背包中盛放哪些物品,使得再不超过背包容量的基础上,物品的总价值最大。 
//思路1:记忆化搜索
//时间复杂度:O(n*C)
//空间复杂度:O(n*C)
//其中n为物品个数,C为背包容量
/*
class Knapsack01
{
	private:
		vector<vector<int>> memo;
		//用[0...index]的物品,填充容量为c的背包的最大价值
		int bestValue(const vector<int> &w, const vector<int> v, int index, int C)
		{
			if(index < 0 || C <= 0)
			{
				return 0;
			}
			if(memo[index][C] != -1 )
			{
				return memo[index][C];
			}
			int res = bestValue(w, v, index - 1, C);
			if(C >= w[index])
			{
				res = max(res, v[index] + bestValue(w, v, index-1, C - w[index]));
				memo[index][C] = res;
			}
			return res;
		}
		
	public:
		int knapsack01(const vector<int> &w, const vector<int> &v, int C)
		{
		    assert(w.size() == v.size());
			int n = w.size();
			memo = vector<vector<int>>(n, vector<int>(C + 1, -1));
			return bestValue(w, v, n-1, C);
		}
};
*/
//思路2:动态规划
//F(n,C) = max(F(i-1,c),v(i) + F(i-1,c-w(i)))
/*
class Knapsack01
{
public:
	int knapsack01(const vector<int> &w, const vector<int> &v, int C)
	{
		assert(w.size() == v.size());
		int n = w.size();
		if(n == 0)
		{
			return 0;
		}
		vector<vector<int>> memo(n, vector<int>(C + 1, -1));
		//递推第一行
		for(int j = 0; j <= C; j++)
		{
			memo[0][j] = (j >= w[0] ? v[0] : 0);
		}
		//递推[2..n]行
		for(int i = 1; i < n; i++)
		{
			for(int j = 0; j <= C; j++)
			{	
				memo[i][j] = memo[i-1][j];
				if(j >= w[i])
				{
					memo[i][j] = max(memo[i][j], v[i] + memo[i-1][j-w[i]]);
				}
			}
		}
		return memo[n-1][C];
	}
};
*/
//优化1:
//第i行元素只依赖于第i-1行元素,理论上只需要保持2行元素,两行轮流使用
//降低空间复杂度到O(2*C) = O(C)
/*
class Knapsack01
{
public:
	int knapsack01(const vector<int> &w, const vector<int> &v, int C)
	{
		assert(w.size() == v.size());
		int n = w.size();
		if(n == 0)
		{
			return 0;
		}
		vector<vector<int>> memo(2, vector<int>(C + 1, -1));
		//递推第一行
		for(int j = 0; j <= C; j++)
		{
			memo[0][j] = (j >= w[0] ? v[0] : 0);
		}
		//递推[2..n]行
		for(int i = 1; i < n; i++)
		{
			for(int j = 0; j <= C; j++)
			{	
				memo[i%2][j] = memo[(i-1)%2][j];
				if(j >= w[i])
				{
					memo[i%2][j] = max(memo[i%2][j], v[i] + memo[(i-1)%2][j-w[i]]);
				}
			}
		}
		return memo[(n-1)%2][C];
	}
};
*/
//优化2:
//只使用一行来储存
//降低空间复杂度到O(1*C) = O(C)
class Knapsack01
{
public:
	int knapsack01(const vector<int> &w, const vector<int> &v, int C)
	{
		assert(w.size() == v.size());
		int n = w.size();
		if(n == 0)
		{
			return 0;
		}
		vector<int> memo(C + 1, -1);
		//递推第一行
		for(int j = 0; j <= C; j++)
		{
			memo[j] = (j >= w[0] ? v[0] : 0);
		}
		//递推[2..n]行
		for(int i = 1; i < n; i++)
		{
			for(int j = C; j >= w[i]; j--)
			{	
				memo[j] = max(memo[j], v[i] + memo[j-w[i]]);
			}
		}
		return memo[C];
	}
};

int main()
{
	int n, W;
	cin>>n>>W;
	int v,w;
	vector<int> vs, ws;
	for(int i = 0; i < n; i ++)
	{
		cin>>w>>v;
		vs.push_back(v);
		ws.push_back(w);
	}
	cout<<Knapsack01().knapsack01(ws, vs, W)<<endl;
	return 0;
}
//0-1背包问题的变种：
//多重背包问题:每个物品不止1个,有num(i)个
//完全背包问题:每个物品可以无限使用
//多维费用背包问题:要考虑物品的体积和重量两个维度或者多个维度
//物品之间加入更多约束:物品间可以互相排斥,也可以互相依赖
