#include <iostream>
#include <cassert>
#include <algorithm>
#include <stack>
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
		void postorder(TreeNode* root, vector<int> &res)
		{
			if(root)
			{
				postorder(root->left, res);
				postorder(root->right, res);
				res.push_back(root->val);
			}
		}
		vector<int> postorderTraversal(TreeNode* root)
		{
			vector<int> res;
			postorder(root, res);
			return res;
		}
};
//拓展:341
