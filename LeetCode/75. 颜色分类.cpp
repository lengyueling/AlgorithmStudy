#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution
{
	public:
		void sortColors(vector<int>& nums)
		{
			//num[i..two-1] == 1
			int zero = -1;			//nums[0...zero] == 0
			int two = nums.size();	//num[two...n-1] == 2
			for(int i = 0; i < two;)
			{
				if(nums[i] == 1)
				{
					i++;
				}
				else if(nums[i] == 2)
				{
					two--;
					swap(nums[i], nums[two]);
				}
				else if(nums[i] == 0)
				{
					zero++;
					swap(nums[zero], nums[i]);
					i++;
				}
			}
		}
};

int main()
{

	return 0;
}

/*
//版本1:不会做的情况下直接写一个排序即可
class Solution
{
public:
	void sortColors(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
	}
};
*/

/*
//版本2:计数排序,分别统计0,1,2的元素个数
class Solution
{
public:
	void sortColors(vector<int>& nums)
	{
		//三个元素的频率
		int count[3] = {0};
		for(int i = 0; i < nums.size(); i++)
		{
			assert(nums[i] >= 0 && nums[i] <= 2);
			count[nums[i]] ++;
		}
		//数组的当前位置
		int index = 0;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < count[i]; j++)
			{
				nums[index++] = i;
			}
		}
	}
};
*/

//版本3:三路快排
//时间复杂度O(n) 空间复杂度O(1) 只遍历了一遍
//拓展: 88 215题

