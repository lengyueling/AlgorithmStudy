#include <iostream>
#include <cassert>
#include <algorithm>
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
		vector<string> binaryTreePaths(TreeNode* root)
		{
			//每一层都有一个res
			vector<string> res;
			//递归终止条件
			if(root == nullptr)
			{
				return res;
			}
			if(root->left == NULL && root->right == NULL)
			{
				res.push_back(to_string(root->val));
				return res;
			}
			//递归过程
			vector<string> leftString = binaryTreePaths(root->left);
			for(int i = 0; i < leftString.size(); i++)
			{
				res.push_back(to_string(root->val) + "->" + leftString[i]);
			}
			
			vector<string> rightString = binaryTreePaths(root->right);
			for(int i = 0; i < rightString.size(); i++)
			{
				res.push_back(to_string(root->val) + "->" + rightString[i]);
			}
			return res;
		}
};

//拓展:113 129
