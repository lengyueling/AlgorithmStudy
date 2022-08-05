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
		long long int pathSum(TreeNode* root, long long int targetSum)
		{
			if (root == nullptr)
			{
				return 0;
			}
			long long int res = findPath(root, targetSum);
			res += pathSum(root->left, targetSum);
			res += pathSum(root->right, targetSum);
			return res;
		}
	private:
		long long int findPath(TreeNode* node, long long int num)
		{
			if (node == nullptr)
			{
				return 0;
			}
			long long int res = 0;
			if (node->val == num)
			{
				res += 1;
			}
			res += findPath(node->left, num - node->val);
			res += findPath(node->right, num - node->val);
			return res;
		}
};
//拓展:111 404
