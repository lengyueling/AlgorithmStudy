#include <iostream>
#include <cassert>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
	public:
		vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
		{
			//元素 频次
			map<int,int> record;
			//填充record,每出现一次频次+1
			for(int i = 0; i < nums1.size(); i++)
			{
				record[nums1[i]]++;
			}
			vector<int> resultVec;
			for(int i = 0; i < nums2.size(); i++)
			{
				if(record[nums2[i]] > 0)
				{
					resultVec.push_back(nums2[i]);
					record[nums2[i]]--;
				}
			}
			return resultVec;
		}
};
