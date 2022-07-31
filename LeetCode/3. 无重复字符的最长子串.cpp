#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution
{
	public:
		int lengthOfLongestSubstring(string s)
		{
			int freq[256] = {0};	//当前字符出现的次数
			int l = 0, r = -1;
			int res = 0;
			while(l < s.size())
			{
				//如果当前字符没有出现过 r右移,设置freq[++r]
				if(r + 1 < s.size() && freq[s[r+1]] == 0)
				{
					r++;
					freq[s[r]]++;
				}
				else//如果当前字符出现过 l右移,设置freq[l]
				{
					freq[s[l]]--;
					l++;
				}
				res = max(res, r-l+1);
			}
			return res;
		}
};

int main()
{
	return 0;
}

//滑动窗口
//拓展: 438 76


