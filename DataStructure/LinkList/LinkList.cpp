#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//根据n个元素的数组arr创建一个链表,并返回链表的头
ListNode* createLinkedList(int arr[], int n)
{
	if(n==0)
	{
		return NULL;
	}
	ListNode* head = new ListNode(arr[0]);
	ListNode* curNode = head;
	for(int i = 0; i < n; i++)
	{
		curNode->next = new ListNode(arr[i]);
		curNode = curNode->next;
	}
	return head;
}

//打印以head为头结点的链表信息内容
void printLinkedList(ListNode* head)
{
	ListNode* curNode = head;
	while(curNode != NULL)
	{
		cout<<curNode->val<<"->";
		curNode = curNode->next;
	}
	cout<<"NULL"<<endl;
}

//释放以head为头结点的链表空间
void deleteLinkedList(ListNode* head)
{
	ListNode* curNode = head;
	while(curNode != NULL)
	{
		ListNode* delNode = curNode;
		curNode = curNode->next;
		delete delNode;
	}
}

//反转链表
class Solution
{
	public:
		ListNode* reverseList(ListNode* head)
		{
			ListNode* pre = NULL;
			ListNode* cur = head;
			while (cur != NULL)
			{
				ListNode* next = cur->next;
				cur->next = pre;
				pre = cur;
				cur = next;
			}
			return pre;
		}
};

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(int);
	ListNode* head = createLinkedList(arr, n);
	printLinkedList(head);
	ListNode* head2 = Solution().reverseList(head);
	printLinkedList(head2);
	deleteLinkedList(head2);
	return 0;
}
//拓展:83 86 328 2 445
