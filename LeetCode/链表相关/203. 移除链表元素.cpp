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

//基于版本1的优化:使用一个虚拟的头结点
class Solution
{
	public:
		ListNode* removeElements(ListNode* head, int val)
		{
			//拥有一个虚拟的头结点则真的头结点就有前驱节点了
			ListNode* dummyHead = new ListNode(0);
			dummyHead->next = head;
			ListNode* cur = dummyHead;
			while(cur->next != NULL)
			{
				if(cur->next->val == val)
				{
					ListNode* delNode = cur->next;
					cur->next = delNode->next;
					delete delNode;
				}
				else
				{
					cur = cur->next;
				}
			}
			
			ListNode* retNode = dummyHead->next;
			delete dummyHead;
			
			return retNode;
		}
};

//版本1:
/*
class Solution
{
public:
	ListNode* removeElements(ListNode* head, int val)
	{
		//如果头结点就满足head->val == val则做特殊处理
		//因为可能会从头连续的满足head->val == val所以要使用while循环
		while(head != NULL && head->val == val)
		{
			ListNode* delNode = head;
			head = delNode->next;
			delete delNode;
		}
		
		//如果头结点为NULL,说明当前链表为空
		//则不能head->next
		if(head == NULL)
		{
			return NULL;
		}
		
		ListNode* cur = head;
		while(cur->next != NULL)
		{
			if(cur->next->val == val)
			{
				ListNode* delNode = cur->next;
				cur->next = delNode->next;
				delete delNode;
			}
			else
			{
				cur = cur->next;
			}
		}
		return head;
	}
};
*/

//拓展:82 21
