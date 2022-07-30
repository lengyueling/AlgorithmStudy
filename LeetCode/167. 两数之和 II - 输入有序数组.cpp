#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	vector<int> twoSum(vector<int>& numbers, int target) 
	{
		int low = 0;
		int high = numbers.size() - 1; 
		while(low < high)
		{
			if(numbers[low] + numbers[high] == target)
			{
				return {low+1, high+1};
			}
			else if(numbers[low] + numbers[high] < target)
			{
				low++;
			}
			else
			{
				high--;
			}
		}
		return{-1, -1};
	}
};

int main()
{

	return 0;
}

//版本1:用O(n^2)复杂度的两层for循环来暴力搜索 超时

/*
//版本2:二分搜索 O(nlogn)的时间复杂度
class Solution 
{
public:
	vector<int> twoSum(vector<int>& numbers, int target) 
	{
		for(int i = 0; i < numbers.size(); ++i)
		{
			int low = i+1;
			int high = numbers.size() - 1;
			while(low <= high)
			{
				int mid = low+(high-low)/2;
				if(numbers[mid] + numbers[i] == target)
				{
					return {i+1, mid+1};
				}
				else if(numbers[mid] + numbers[i] > target)
				{
					high = mid -1;
				}
				else
				{
					low = mid + 1;
				}
			}
		}
		return{-1, -1};
	}
};
*/

//版本3:对撞指针
//时间复杂度O(n)
/*
class Solution 
{
public:
	vector<int> twoSum(vector<int>& numbers, int target) 
	{
		int low = 0;
		int high = numbers.size() - 1; 
		while(low < high)
		{
			if(numbers[low] + numbers[high] == target)
			{
				return {low+1, high+1};
			}
			else if(numbers[low] + numbers[high] < target)
			{
				low++;
			}
			else
			{
				high--;
			}
		}
		return{-1, -1};
	}
};
*/
//拓展: 125 344 345 11题

