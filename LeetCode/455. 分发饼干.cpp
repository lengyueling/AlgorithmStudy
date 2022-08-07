#include <iostream>
#include <cassert>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int findContentChildren(vector<int>& g, vector<int>& s)
	{
		sort(g.begin(),g.end(), greater<int>());
		sort(s.begin(),s.end(), greater<int>());
		int res = 0;
		int si = 0;
		int gi = 0;
		while(si < s.size() && gi < g.size())
		{
			if(s[si] >= g[gi])
			{
				res++;
				si++;
				gi++;
			}
			else
			{
				gi++;
			}
		}
		return res;
	}
};
//拓展:392

int main()
{
	int g1[] = {1, 2, 3};
	vector<int> gv1(g1, g1 + sizeof(g1)/sizeof(int));
	int s1[] = {1, 3};
	vector<int> sv1(s1, s1 + sizeof(s1)/sizeof(int));
	cout <<"ans:" <<Solution().findContentChildren(gv1, sv1) << endl;
	
	return 0;
}
