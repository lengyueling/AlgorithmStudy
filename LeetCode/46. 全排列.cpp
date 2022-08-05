#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

//思路2:使用回溯
class Solution
{
	private:
		vector<vector<int>> res;
		vector<bool> used;
		//p中保存了当前有index个元素的排列
		//向这个排列的末尾添加index+1个元素,获得一个有index+1个元素的排列
		void generatePermutation(const vector<int>& nums, int index, vector<int>& p)
		{
			
			if(index == nums.size())
			{
				res.push_back(p);
				return;
			}
			for(int i = 0; i < nums.size(); i++)
			{
				if(!used[i])
				{
					p.push_back(nums[i]);
					used[i] = true;
					generatePermutation(nums, index + 1, p);
					//递归到底了,回溯遍历过的数
					p.pop_back();
					used[i] = false;
				}
				
			}
			
		}	

	public:
		vector<vector<int>> permute(vector<int>& nums)
		{
			res.clear();
			if(nums.size() == 0)
			{
				return res;
			}
			used = vector<bool>(nums.size(), false);
			vector<int> p;
			generatePermutation(nums, 0, p);
			return res;
		}
};

//思路1:使用全排列函数
/*
class Solution
{
	public:
		vector<vector<int>> permute(vector<int>& nums)
		{
			for (int i = 0; i < nums.size() - 1; ++i)
			{
				if (nums[i] > nums[i + 1])
				{
					sort(nums.begin(), nums.end());
					break;
				}
			}
			vector<vector<int>> res;
			do
			{
				res.emplace_back(nums);
			}
			while (next_permutation(nums.begin(), nums.end()));
			return res;
		}
};
*/

//拓展:47
