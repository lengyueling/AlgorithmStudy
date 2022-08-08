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
		ListNode* swapPairs(ListNode* head)
		{	
			ListNode* dummyHead = new ListNode(0);
			dummyHead->next = head;
			ListNode* p = dummyHead;
			
			while(p->next && p->next->next)
			{
				ListNode* node1 = p->next;
				ListNode* node2 = node1->next;
				ListNode* next = node2->next;
				
				node2->next = node1;
				node1->next = next;
				p->next = node2;
				p = node1;
			}
			ListNode* retNode = dummyHead->next;
			delete dummyHead;
			return retNode;
		}
};

//拓展:25 147 148
