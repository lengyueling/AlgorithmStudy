#include <iostream>
#include <cassert>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

//使用hashset 降低时间复杂度从O(nlongn)到O(n)
class Solution
{
	public:
		vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
		{
			unordered_set<int> record;
			for(int i = 0; i < nums1.size(); i++)
			{
				record.insert(nums1[i]);
			}
			unordered_set<int> resultSet;
			for(int i = 0; i < nums2.size(); i++)
			{
				if(record.find(nums2[i]) != record.end())
				{
					resultSet.insert(nums2[i]);
				}
			}
			vector<int> resultVec;
			for(unordered_set<int>::iterator iter = resultSet.begin(); iter != resultSet.end(); iter++)
			{
				resultVec.push_back(*iter);
			}
			return resultVec;
		}
};
//初始版本 使用set
/*
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
*/

//简介版本
/*
class Solution
{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		set<int> record(nums1.begin(), nums1.end());
		set<int> resultSet;
		for(int i = 0; i < nums2.size(); i++)
		{
			if(record.find(nums2[i]) != record.end())
			{
				resultSet.insert(nums2[i]);
			}
		}
		return vector<int>(resultSet.begin(),resultSet.end());
	}
};
*/
