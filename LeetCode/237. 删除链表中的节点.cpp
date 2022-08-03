#include <iostream>
#include <cassert>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Definition for singly - linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
	public:
		void deleteNode(ListNode* node)
		{
			if(node == NULL)
			{
				return;
			}
			if(node->next == NULL)
			{
				delete node;
				node = NULL;
				return;
				
			}
			node->val = node->next->val;
			ListNode* delNode = node->next;
			node->next = delNode->next;
			delete delNode;
		}
};
