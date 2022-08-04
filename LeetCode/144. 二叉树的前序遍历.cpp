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
		struct Command
		{
			bool s;
			TreeNode* node;
			Command(bool s, TreeNode* node) : s(s), node(node){}
		};
		vector<int> preorderTraversal(TreeNode* root)
		{
			vector<int> res;
			if (root)
			{
				stack<Command> stack;
				stack.push(Command(true,root));
				while(!stack.empty())
				{
					Command command = stack.top();
					stack.pop();
					if(command.s == false)
					{
						res.push_back(command.node->val);
					}
					else if(command.s == true)
					{
						if(command.node->right)
						{
							stack.push(Command(true, command.node->right));
						}
						if(command.node->left)
						{
							stack.push(Command(true, command.node->left));
						}
						stack.push(Command(false, command.node));
					}
				}
			}
			
			return res;
		}
};

//思路1:递归
/*
class Solution
{
	public:
		void preorder(TreeNode* root, vector<int> &res)
		{
			if(root)
			{
				res.push_back(root->val);
				preorder(root->left, res);
				preorder(root->right, res);
			}
		}
		vector<int> preorderTraversal(TreeNode* root)
		{
			vector<int> res;
			preorder(root, res);
			return res;
		}
};
*/
//拓展:341
