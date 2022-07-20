#include <iostream>
#include <cassert>
#include <ctime>
#include <queue>
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
		Destory(root);
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
	
	//前序遍历
	void PreOrder()
	{
		PreOrder(root);
	}
	
	//中序遍历
	void InOrder()
	{
		InOrder(root);
	}
	
	//后序遍历
	void PostOrder()
	{
		PostOrder(root);
	}
	
	//层序遍历
	void LevelOrder()
	{
		queue<Node*> q;
		q.push(root);
		while(!q.empty())
		{
			Node *node = q.front();
			q.pop();
			cout<<node->key<<endl;
			if(node->left)
			{
				q.push(node->left);
			}
			if(node->right)
			{
				q.push(node->right);
			}
		}
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
		}
		else//key > node->key
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
	
	//对以node为根的二叉搜索树进行先序遍历
	void PreOrder(Node *node)
	{
		if(node != NULL)
		{
			cout<<node->key<<endl;
			PreOrder(node->left);
			PreOrder(node->right);
		}
	}
	
	//对以node为根的二叉搜索树进行中序遍历
	void InOrder(Node *node)
	{
		if(node != NULL)
		{
			PreOrder(node->left);
			cout<<node->key<<endl;
			PreOrder(node->right);
		}
	}
	
	//对以node为根的二叉搜索树进行后序遍历
	void PostOrder(Node *node)
	{
		if(node != NULL)
		{
			PreOrder(node->left);
			
			PreOrder(node->right);
			cout<<node->key<<endl;
		}
	}
	
	//对整个二叉树释放空间实际上就是进行了一次后序遍历
	void Destory(Node *node)
	{
		if(node != NULL)
		{
			Destory(node->left);
			Destory(node->right);
			delete(node);
			count--;
		}
	}
};

int main() 
{
	srand(time(NULL));
	BST<int,int> bst = BST<int,int>();
	
	// 取n个取值范围在[0...m)的随机整数放进二分搜索树中
	int N = 10;
	int M = 100;
	for( int i = 0 ; i < N ; i ++ )
	{
		int key = rand()%M;
		// 为了后续测试方便,这里value值取和key值一样
		int value = key;
		cout<<key<<" ";
		bst.Insert(key,value);
	}
	cout<<endl;
	
	// 测试二分搜索树的size()
	cout<<"Size: "<<bst.Size()<<endl<<endl;
	
	// 测试二分搜索树的前序遍历 preOrder
	cout<<"PreOrder: "<<endl;
	bst.PreOrder();
	cout<<endl;
	
	// 测试二分搜索树的中序遍历 inOrder
	cout<<"InOrder: "<<endl;
	bst.InOrder();
	cout<<endl;
	
	// 测试二分搜索树的后序遍历 postOrder
	cout<<"PostOrder: "<<endl;
	bst.PostOrder();
	cout<<endl;
	
	// 测试二分搜索树的层序遍历 levelOrder
	cout << "LevelOrder: " << endl;
	bst.LevelOrder();
	return 0;
}
