#include <iostream>
#include <cassert>
#include <algorithm>
#include <unordered_set>
using namespace std;
//思路1:暴力O(n^2)
//思路2:滑动窗口+查找表 O(n)

class Solution
{
	public:
		bool containsNearbyDuplicate(vector<int>& nums, int k)
		{
			unordered_set<int> record;
			for(int i = 0; i < nums.size(); i++)
			{
				//如果新遍历的元素和查找表中元素相同,说明满足题意
				if(record.find(nums[i]) != record.end())
				{
					return true;
				}
				//否则插入新元素
				record.insert(nums[i]);
				//保持record中最多有k个元素
				//也就是保证i-j<=k
				if(record.size() == k+1)
				{
					//删除最左边的元素因为最左边的元素已经不满足i-j<=k了
					record.erase(nums[i-k]);
				}
			}
			return false;
		}
};
