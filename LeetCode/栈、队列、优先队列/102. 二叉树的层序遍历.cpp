#include <iostream>
#include <cassert>
#include <algorithm>
#include <queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> res;
		if(root == NULL)
		{
			return res;
		}
		queue<pair<TreeNode*, int>> q;
		q.push(make_pair(root,0));
		while(!q.empty())
		{
			TreeNode* node = q.front().first;
			int level = q.front().second;
			q.pop();
			//说明当前level的res还没有被创建
			//如果被创建了 res == res.size()+1
			if(level == res.size())
			{
				res.push_back(vector<int>());
			}
			res[level].push_back(node->val);
			if(node->left)
			{
				q.push(make_pair(node->left, level + 1));
			}
			if(node->right)
			{
				q.push(make_pair(node->right, level + 1));
			}
		}
		return res;
	}
};


//拓展:107 103 199
