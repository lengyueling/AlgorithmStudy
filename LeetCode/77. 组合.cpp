#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;


//优化:使用回溯解决组合问题.通过减枝进行优化
class Solution
{
private:
	vector<vector<int>> res;
	
	//求解C(n,k),当前已经找到的组合存储在c中,需要从start开始搜索新的元素
	void generateCombination(int n, int k, int start, vector<int> &c)
	{
		if(c.size() == k)
		{
			res.push_back(c);
			return;
		}
		//当前还有k-c.size()个空位,所以[i...n]中至少要有k-c.size()个元素
		//所以i最多为n-(k-c.size())+1
		for(int i = start; i <= n-(k-c.size()) + 1; i++)
		{
			c.push_back(i);
			generateCombination(n, k, i + 1, c);
			c.pop_back();
		}
	}	
	
public:
	vector<vector<int>> combine(int n, int k) 
	{
		res.clear();
		if(n <= 0 || k <= 0 || k > n)
		{
			return res;
		}
		vector<int> c;
		generateCombination(n, k, 1, c);
		return res;
	}
};
//方法:使用回溯解决组合问题
/*
class Solution
{
	private:
		vector<vector<int>> res;
	
		//求解C(n,k),当前已经找到的组合存储在c中,需要从start开始搜索新的元素
		void generateCombination(int n, int k, int start, vector<int> &c)
		{
			if(c.size() == k)
			{
				res.push_back(c);
				return;
			}
			for(int i = start; i <= n; i++)
			{
				c.push_back(i);
				generateCombination(n, k, i + 1, c);
				c.pop_back();
			}
		}	

	public:
		vector<vector<int>> combine(int n, int k) 
		{
			res.clear();
			if(n <= 0 || k <= 0 || k > n)
			{
				return res;
			}
			vector<int> c;
			generateCombination(n, k, 1, c);
			return res;
		}
};
*/

//拓展:39 40 216 78 90 401
