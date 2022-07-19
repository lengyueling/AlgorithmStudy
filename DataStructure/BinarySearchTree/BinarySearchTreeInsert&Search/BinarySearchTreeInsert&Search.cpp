#include<iostream>
#include <cassert>
#include <ctime>
#include "FileOps.h"
using namespace std;

//二分查找树的实现实际上就是字典数据结构
//二分查找树的优势:
//不仅可高效的查找数据，还可以高效的插入，删除数据，动态维护数据
//可以方便的回答min max floor ceil rank select等数据之间关系的问题
//二分查找树的特点：
//是二叉树
//每个结点的键值大于左孩子，小于右孩子
//以左右孩子为根的子树认为二分搜索树
//不一定是完全二叉树

template <typename Key,typename Value>
class BST 
{
private:
	//一个结点
	struct Node
	{
		Key key;
		Value value;
		Node *left;
		Node *right;
		
		Node(Key key, Value value)
		{
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
	};
	//根结点
	Node *root;
	int count;
	
public:
	BST() 
	{
		root = NULL;
		count = 0;
	}
	~BST() 
	{
		//TODO	
	}
	int Size()
	{
		return count;
	}
	bool IsEmpty()
	{
		return count == 0;
	}
	void Insert(Key key, Value value)
	{
		root = Insert(root, key, value);
	}

	bool Contain(Key key)
	{
		return Contain(root, key);
	}
	
	Value* Search(Key key)
	{
		return Search(root, key);
	}
private:
	//向以node为根的二叉搜索树中插入结点（key,value）
	//返回插入新结点后的二叉搜索树的根
	Node* Insert(Node *node, Key key, Value value)
	{
		//如果结点 == null则新建结点
		if(node == NULL)
		{
			count++;
			return new Node(key,value);
		}
		if(key == node->key)
		{
			node->value = value;
		}
		else if(key < node->key)
		{
			node->left = Insert(node->left, key, value);
		}else//key > node->key
		{
			node->right = Insert(node->right, key, value);
		}
		return node;
	}
	
	//在以node为根的二叉搜索树中查找key所对应的value
	Value* Search(Node* node,Key key)
	{
		if(node == NULL)
		{
			return NULL;
		}
		if(key == node->key)
		{
			return &(node->value);
		}
		else if(key < node->key)
		{
			return Search(node->left, key);
		}
		else
		{
			return Search(node->right, key);
		}
	}
	
	//查看以node为根的二叉搜索树中是否包含键值为key的结点
	bool Contain(Node* node, Key key)
	{
		if(node == NULL)
		{
			return false;
		}
		if(key == node->key)
		{
			return true;
		}
		else if(key < node->key)
		{
			return Contain(node->left, key);
		}
		else//key > node->key
		{
			return Contain(node->right, key);
		}
	}
	
};

// 测试二分搜索树和顺序查找表之间的性能差距
// 二分搜索树的性能远远优于顺序查找表
int main() 
{
	// 使用圣经作为我们的测试用例
	string filename = "bible.txt";
	vector<string> words;
	if( FileOps::readFile(filename, words) ) 
	{
		cout << "There are totally " << words.size() << " words in " << filename << endl;
		// 测试 BST
		time_t startTime = clock();
		
		// 统计圣经中所有词的词频
		// 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
		// 在这里只做性能测试用
		BST<string, int> bst = BST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) 
		{
			int *res = bst.Search(*iter);
			if (res == NULL)
			{
				bst.Insert(*iter, 1);
			}
			else
			{
				(*res)++;
			}	
		}
		// 输出圣经中god一词出现的频率
		if(bst.Contain("god"))
		{
			cout << "god:" << *bst.Search("god") << endl;
		}	
		else
		{
			cout << "No word 'god' in " << filename << endl;
		}
		time_t endTime = clock();
		cout << "BST:Time:" << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
		cout << endl;
	}
	return 0;
}
