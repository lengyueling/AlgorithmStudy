#include <iostream>
#include <cassert>
#include <algorithm>
#include <unordered_map>
using namespace std;
//思路1:暴力O(n^4)
//思路2:D放到查找表 O(n^3)
//思路3:C+D的每一种可能性都放到查找表 O(n^2)

class Solution
{
	public:
		int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
		{
			unordered_map<int, int> record;
			for(int i = 0; i < nums3.size(); i++)
			{
				for(int j = 0; j < nums4.size(); j++)
				{
					record[nums3[i]+nums4[j]] ++;
				}
			}
			int res = 0;
			for(int i = 0; i < nums1.size(); i++)
			{
				for(int j = 0; j < nums2.size(); j++)
				{
					if(record.find(0 - nums1[i] - nums2[j]) != record.end())
					{
						res += record[0 - nums1[i] - nums2[j]];
					}
				}
			}
			return res;
		}
};
//拓展:49
