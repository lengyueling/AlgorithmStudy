#include <iostream>
#include <cassert>
#include <ctime>
#include <queue>
using namespace std;

//二分查找树的实现实际上就是字典数据结构
//二分查找树的优势:
//不仅可高效的查找数据，还可以高效的插入，删除数据，动态维护数据
//可以方便的回答min max floor ceil successor(后继) predecessor(前驱) rank select等数据之间关系的问题
//二分查找树的特点：
//是二叉树
//每个结点的键值大于左孩子，小于右孩子
//以左右孩子为根的子树认为二分搜索树
//不一定是完全二叉树

template <typename Key, typename Value>
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

			Node(Node *node)
			{
				this->key = node->key;
				this->value = node->value;
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
			while (!q.empty())
			{
				Node *node = q.front();
				q.pop();
				cout << node->key << endl;
				if (node->left)
				{
					q.push(node->left);
				}
				if (node->right)
				{
					q.push(node->right);
				}
			}
		}

		//求最小值的键值
		Key Minimum()
		{
			assert(count != 0);
			Node* minNode = Minimum(root);
			return minNode->key;
		}

		//求最大值的键值
		Key Maximum()
		{
			assert(count != 0);
			Node* maxNode = Maximum(root);
			return maxNode->key;
		}

		//从二叉树中删除最小值所在的结点
		void RemoveMin()
		{
			if (root)
			{
				root = RemoveMin(root);
			}
		}

		//从二叉树中删除最大值所在的结点
		void RemoveMax()
		{
			if (root)
			{
				root = RemoveMax(root);
			}
		}
		//删除任意结点
		void Remove(Key key)
		{
			root = Remove(root, key);
		}

	private:
		//向以node为根的二叉搜索树中插入结点（key,value）
		//返回插入新结点后的二叉搜索树的根
		Node* Insert(Node *node, Key key, Value value)
		{
			//如果结点 == null则新建结点
			if (node == NULL)
			{
				count++;
				return new Node(key, value);
			}
			if (key == node->key)
			{
				node->value = value;
			}
			else if (key < node->key)
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
		Value* Search(Node* node, Key key)
		{
			if (node == NULL)
			{
				return NULL;
			}
			if (key == node->key)
			{
				return &(node->value);
			}
			else if (key < node->key)
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
			if (node == NULL)
			{
				return false;
			}
			if (key == node->key)
			{
				return true;
			}
			else if (key < node->key)
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
			if (node != NULL)
			{
				cout << node->key << endl;
				PreOrder(node->left);
				PreOrder(node->right);
			}
		}

		//对以node为根的二叉搜索树进行中序遍历
		void InOrder(Node *node)
		{
			if (node != NULL)
			{
				PreOrder(node->left);
				cout << node->key << endl;
				PreOrder(node->right);
			}
		}

		//对以node为根的二叉搜索树进行后序遍历
		void PostOrder(Node *node)
		{
			if (node != NULL)
			{
				PreOrder(node->left);

				PreOrder(node->right);
				cout << node->key << endl;
			}
		}

		//对整个二叉树释放空间实际上就是进行了一次后序遍历
		void Destory(Node *node)
		{
			if (node != NULL)
			{
				Destory(node->left);
				Destory(node->right);
				delete (node);
				count--;
			}
		}

		//在以node为根的二叉搜索树中，返回最大键值的结点
		Node* Maximum(Node *node)
		{
			if (node->right == NULL)
			{
				return node;
			}
			return Maximum(node->right);
		}

		//在以node为根的二叉搜索树中，返回最小键值的结点
		Node* Minimum(Node *node)
		{
			if (node->left == NULL)
			{
				return node;
			}
			return Maximum(node->left);
		}

		//删除以node为根的二分搜索树中的最小结点
		//返回删除结点后新的二分搜索树的根
		Node* RemoveMin(Node* node)
		{
			if (node->left == NULL)
			{
				//如果存在右结点则让右结点作为子树的根节点，如果不存在则让null作为根节点
				Node * rightNode = node->right;
				delete node;
				count --;
				return rightNode;
			}
			node->left = RemoveMin(node->left);
			return node;
		}

		//删除以node为根的二分搜索树中的最大结点
		//返回删除结点后新的二分搜索树的根
		Node* RemoveMax(Node* node)
		{
			if (node->right == NULL)
			{
				//如果存在左结点则让左结点作为子树的根节点，如果不存在则让null作为根节点
				Node * leftNode = node->left;
				delete node;
				count --;
				return leftNode;
			}
			node->right = RemoveMax(node->right);
			return node;
		}

		//删除以node为根的二分搜索树中键值为key的结点
		//返回删除结点后新的二分搜索树的根
		Node* Remove(Node* node, Key key)
		{
			if (node == NULL)
			{
				return NULL;
			}
			if (key < node->key)
			{
				node->left = Remove(node->left, key);
				return node;
			}
			else if (key > node->key)
			{
				node->right = Remove(node->right, key);
				return node;
			}
			//HubbardDeletion
			else//key ==node->key
			{
				if (node->left == NULL)
				{
					Node *rightNode = node->right;
					delete node;
					count--;
					return rightNode;
				}
				else if (node->right == NULL)
				{
					Node *leftNode = node->left;
					delete node;
					count --;
					return leftNode;
				}

				else//node->left != NULL &&node->right != NULL
				{
					//待删除节点左右子树均不为空的情况
					//找到比待删除节点大的最小节点, 即待删除节点右子树的最小节点
					//用这个节点顶替待删除节点的位置
					Node *successor = new Node (Minimum(node->right));
					count ++;
					successor->right = RemoveMin(node->right);
					successor->left = node->left;
					delete node;
					count --;
					return successor;
				}
			}
		}
};

//测试移除最大和最小键值的结点
void TestRemoveMaxMin()
{
	srand(time(NULL));
	BST<int, int> bst = BST<int, int>();

	// 取n个取值范围在[0...m)的随机整数放进二分搜索树中
	int n = 100;
	int m = 100;
	for ( int i = 0 ; i < n ; i ++ )
	{
		int key = rand() % m;
		// 为了后续测试方便,这里value值取和key值一样
		int value = key;
		//cout<<key<<" ";
		bst.Insert(key, value);
	}
	// 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的

	// 测试 removeMin
	// 输出的元素应该是从小到大排列的
	cout << "Test removeMin: " << endl;
	while ( !bst.IsEmpty() )
	{
		cout << "min: " << bst.Minimum() << " , ";
		bst.RemoveMin();
		cout << "After removeMin, size = " << bst.Size() << endl;
	}
	cout << endl;


	for ( int i = 0 ; i < n ; i ++ )
	{
		int key = rand() % n;
		// 为了后续测试方便,这里value值取和key值一样
		int value = key;
		//cout<<key<<" ";
		bst.Insert(key, value);
	}
	// 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的

	// 测试 removeMax
	// 输出的元素应该是从大到小排列的
	cout << "Test removeMax: " << endl;
	while ( !bst.IsEmpty() )
	{
		cout << "max: " << bst.Maximum() << " , ";
		bst.RemoveMax();
		cout << "After removeMax, size = " << bst.Size() << endl;
	}
}

void Shuffle( int arr[], int n )
{

	srand( time(NULL) );
	for ( int i = n - 1 ; i >= 0 ; i -- )
	{
		int x = rand() % (i + 1);
		swap( arr[i], arr[x] );
	}
}

//测试删除任意结点
void TestRemove()
{
	srand(time(NULL));
	BST<int, int> bst = BST<int, int>();

	// 取n个取值范围在[0...n)的随机整数放进二分搜索树中
	int n = 10000;
	for ( int i = 0 ; i < n ; i ++ )
	{
		int key = rand() % n;
		// 为了后续测试方便,这里value值取和key值一样
		int value = key;
		bst.Insert(key, value);
	}
	// 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的

	// order数组中存放[0...n)的所有元素
	int order[n];
	for ( int i = 0 ; i < n ; i ++ )
		order[i] = i;
	// 打乱order数组的顺序
	Shuffle( order, n );

	// 乱序删除[0...n)范围里的所有元素
	for ( int i = 0 ; i < n ; i ++ )
		if ( bst.Contain( order[i] ))
		{
			bst.Remove( order[i] );
			cout << "After remove " << order[i] << " size = " << bst.Size() << endl;
		}

	// 最终整个二分搜索树应该为空
	cout << bst.Size() << endl;
}
int main()
{
	TestRemoveMaxMin();
	cout << "-----------------------" << endl;
	TestRemove();
	return 0;
}
