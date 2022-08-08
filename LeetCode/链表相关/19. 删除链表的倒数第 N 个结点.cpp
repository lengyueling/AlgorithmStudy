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

//思路1:先遍历一遍计算链表长度,再遍历一遍删除倒数第n个节点
//思路2:使用双指针pq,通过头和尾都是NULL的特点,全程只需要遍历一遍即可
class Solution
{
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n)
		{
			assert(n>=0);
			ListNode* dummyHead = new ListNode(0);
			dummyHead->next = head;
			ListNode*p = dummyHead;
			ListNode*q = dummyHead;
			for(int i = 0; i < n + 1; i++)
			{
				assert(q);
				q = q->next;
			}
			while(q != NULL)
			{
				p = p->next;
				q = q->next;
			}
			ListNode* delNode = p->next;
			p->next = delNode->next;
			delete delNode;
			ListNode* retNode = dummyHead->next;
			delete dummyHead;
			return retNode;
		}
};

//拓展:61 143 234
