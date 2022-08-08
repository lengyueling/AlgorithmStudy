#include <iostream>
#include <cassert>
#include <algorithm>
#include <set>
using namespace std;
//思路1:暴力O(n^2)
//思路2:滑动窗口+有序查找表 O(nlogn)
//leetcode的测试用例整型会溢出所以要做响应调整

class Solution
{
	public:
		bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
		{
			set<long long int> record;
			for(int i = 0; i < nums.size(); i++)
			{
				//寻找>= abs(v-x) <= t的元素
				//即v-t<=v<=v+t
				//即lower_bound(v-t) <= (v+t)
				if(record.lower_bound((long long)nums[i]-(long long)t) != record.end() && *record.lower_bound((long long)nums[i]-(long long)t) <= (long long)nums[i] + (long long)t)
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
