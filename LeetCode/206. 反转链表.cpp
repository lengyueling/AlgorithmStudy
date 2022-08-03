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

//时间复杂度: O(n)
//空间复杂度: O(1)
class Solution
{
	public:
		ListNode* reverseList(ListNode* head)
		{
			ListNode* pre = NULL;
			ListNode* cur = head;
			while(cur != NULL)
			{
				ListNode* next = cur->next;
				
				cur->next = pre;
				pre = cur;
				cur = next;
			}
			return pre;
		}
};
//拓展:92
