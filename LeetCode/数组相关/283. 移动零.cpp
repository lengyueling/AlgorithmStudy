#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
	public:
		void moveZeroes(vector<int>& nums)
		{
			int k = 0;
			for (int i = 0; i < nums.size(); i++)
			{
				if (nums[i] != 0)
				{
					if (i != k)
					{
						swap(nums[k++], nums[i]);
					}
					else
					{
						k++;
					}
				}
			}
		}
};

int main()
{
	int arr[] = {0, 1, 2, 3, 4, 0};
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	Solution().moveZeroes(vec);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	return 0;
}

/*
//版本1:使用辅助vector用来存非0的元素
class Solution
{
public:
	void moveZeroes(vector<int>& nums)
	{
		vector<int> nonZeroElements;
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i])
			{
				nonZeroElements.push_back(nums[i]);
			}
		}
		for(int i = 0; i < nonZeroElements.size(); i++)
		{
			nums[i] = nonZeroElements[i];
		}
		for(int i = nonZeroElements.size(); i < nums.size(); i++)
		{
			nums[i] = 0;
		}
	}
};
*/

/*
//版本2:不使用辅助vector,降低空间复杂度
class Solution
{
public:
	void moveZeroes(vector<int>& nums)
	{
		int j = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != 0)
			{
				nums[j] = nums[i];
				j++;
			}
		}
		for(int i = nums.size() - 1; i >= j; i--)
		{
			nums[i] = 0;
		}
	}
};
*/

/*
//版本3:使用swap将0元素与非0元素交换
class Solution
{
public:
	void moveZeroes(vector<int>& nums)
	{
		int k = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i]!=0)
			{
				//交换后k所指的元素就是0元素
				//i继续往后找到非0元素与k所指元素交换直到i到末尾
				//此时k以及往后的所有元素都为0了
				swap(nums[k++],nums[i]);
			}
		}
	}
};
*/

/*
//版本4:针对i=j进行局部优化
class Solution
{
public:
	void moveZeroes(vector<int>& nums)
	{
		int k = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != 0)
			{
				if (i != k)
				{
					swap(nums[k++], nums[i]);
				}
				else
				{
					k++;
				}
			}
		}
	}
};
*/
//拓展: 26 27 80题
