//通过一个前序遍历数组和一个后序遍历数组构造树，求和树
#include <iostream>
#include <vector>
using namespace std;
struct Node {
	int root;	//
	int sum;	//左子树节点和+右子树节点和，不包括本节点
	Node* left;
	Node* right;
	Node(int val) : root(val), sum(0), left(nullptr), right(nullptr) {}
};

/** \brief 构造树
 * \param pre 前序数组
 * \param l1 参与运算的当前 前序数组 在原 前序数组 的起始下标
 * \paran r1 参与运算的当前 前序数组 在原 前序数组 的最后下标
 * \param inter 中序数组
 * \param l2 参与运算的当前 中序数组 在原 中序数组 的起始下标
 * \param r2 参与运算的当前 中序数组 在原 中序数组 的最后下标
 */
Node* Plant(vector<int> &pre, int l1, int r1, vector<int> &inter, int l2, int r2)
{
	if(l1 > r1 || l2 > r2)
		return nullptr;
	Node *root = new Node(pre[l1]);
	int tmp = 0;
	for(int i = l2; i < r2+1; ++i)
	{
		if(inter[i] == pre[l1])
		{
			tmp = i;
			break;
		}
	}
	int tmp_len = tmp-l2;
	root->left = Plant(pre, l1+1, l1+tmp_len, inter, l2, tmp-1);
	root->right = Plant(pre, l1+tmp_len+1, r1, inter, tmp+1, r2);
	return root;
}
//构造树
Node* Plant(vector<int> &pre, vector<int> &inter)
{
	int l1 = 0, l2 = 0;
	int r1 = pre.size( )-1;
	int r2 = inter.size( )-1;
	Node *root = nullptr;
	root = Plant(pre, l1, r1, inter, l2, r2);
	return root;
}
//输入长度未知的数组
void InputVector(vector<int>& arry_a)
{
	char c;
	int tmp = 0;
	cin >> tmp;	//读取输入行的第一个字符(2)
	arry_a.push_back(tmp);
	while((c = getchar( )) != '\n') {	//读取输入行的第二个字符(“ ”)
		cin >> tmp;	//读取输入行的第三个字符(3)
		arry_a.push_back(tmp);
	}
}
//后序遍历 构造求和树
void SumfollowShow(Node* tree)
{
	if(tree == nullptr)
		return;
	//左子树
	SumfollowShow(tree->left);
	
	//右子树
	SumfollowShow(tree->right);
	
	//节点
	if(tree->left == nullptr && tree->right != nullptr)
	{
		tree->sum = 0 + 0 +tree->right->root + tree->right->sum;
	}
	else if(tree->left != nullptr && tree->right == nullptr)
	{
		tree->sum = tree->left->root + tree->left->sum + 0 + 0;
	}
	else if(tree->left == nullptr && tree->right == nullptr)
	{
		tree->sum = 0;
	}
	else
	{
		tree->sum = tree->left->root + tree->left->sum +tree->right->root + tree->right->sum;
	}
	//cout << tree->sum << " ";
}
//按照中序遍历打印求和树
void SumInterShow(Node* tree)
{
	if(tree == nullptr)
		return;
	SumInterShow(tree->left);

	cout << tree->sum << " ";

	SumInterShow(tree->right);
}
//中序遍历打印节点值
void InterShow(Node* tree)
{
	if(tree == nullptr)
		return;
	InterShow(tree->left);

	cout << tree->root << " ";

	InterShow(tree->right);
}
int main( )
{
	vector<int> pre;
	vector<int> inter;
	InputVector(pre);
	InputVector(inter);
	Node *root = nullptr;
	root = Plant(pre, inter);    //造树
	SumfollowShow(root);    //构造求和树
	SumInterShow(root);    //打印
	cout << endl;
	return 0;
}


