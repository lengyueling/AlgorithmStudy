#include <iostream>
#include <cassert>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
	public:
		vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
		{
			set<int> record;
			for(int i = 0; i < nums1.size(); i++)
			{
				record.insert(nums1[i]);
			}
			set<int> resultSet;
			for(int i = 0; i < nums2.size(); i++)
			{
				if(record.find(nums2[i]) != record.end())
				{
					resultSet.insert(nums2[i]);
				}
			}
			vector<int> resultVec;
			for(set<int>::iterator iter = resultSet.begin(); iter != resultSet.end(); iter++)
			{
				resultVec.push_back(*iter);
			}
			return resultVec;
		}
};
