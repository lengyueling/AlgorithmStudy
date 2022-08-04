#include <iostream>
#include <cassert>
#include <algorithm>
#include <queue>
using namespace std;

//思路1:扫描一遍进行统计频率,排序前k个出现频率最高的元素,O(nlogn)
//思路2:使用优先队列,维护含有k个元素的优先队列,O(nlogk)
class Solution
{
	public:
		vector<int> topKFrequent(vector<int>& nums, int k)
		{
			//统计每个元素出现的频率
			unordered_map<int, int> freq;
			for(int i = 0; i < nums.size(); i++)
			{
				freq[nums[i]]++;
			}
			
			//扫描freq,维护当前频率最高的k个元素
			//在优先队列中,按照频率排序,所以数据对是(频率,元素)的形式
			priority_queue<pair<int,int>, vector<pair<int, int>> , greater<pair<int,int>>> pq;
			for(unordered_map<int, int>::iterator iter = freq.begin(); iter!=freq.end(); iter++)
			{
				if(pq.size() == k)
				{
					if(iter->second > pq.top().first)
					{
						pq.pop();
						pq.push(make_pair(iter->second, iter->first));
					}
				}
				else
				{
					pq.push(make_pair(iter->second, iter->first));
				}
			}
			vector<int> res;
			while(!pq.empty())
			{
				res.push_back(pq.top().second);
				pq.pop();
			}
			return res;
		}
};
//思路3:维护优先队列,时间复杂度O(nlog(n-k))

//拓展:23
