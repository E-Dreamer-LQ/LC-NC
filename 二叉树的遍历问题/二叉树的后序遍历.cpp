// leetcode145-二叉树的后序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
//  后序遍历： 左孩子 -》 右孩子   -》 根节点

#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 第一种写法
class Solution2 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		stack <TreeNode*> sta;
		vector<int> res;
		if (root != nullptr) return res;
		sta.push(root);
		while (!sta.empty()) {
			TreeNode* temp = sta.top();
			sta.pop();
			if (temp->left != nullptr) sta.push(temp->left);
			if (temp->right != nullptr) sta.push(temp->right);
			res.push_back(temp->val);
		}
		// 结果序列逆序
		reverse(res.begin(), res.end());
		return res;
	}
};

// 第二种方法 (重点理解)
vector<int> PostOrderLoop(TreeNode* root)
{
	stack<TreeNode*> mystack;
	vector<int> ans;
	TreeNode* curr = root;
	TreeNode* pre = NULL;

	while (curr || !mystack.empty())
	{
		while (curr)
		{
			mystack.push(curr);
			curr = curr->left;
		}
		curr = mystack.top();

		//若右节点已经访问过或者没有右节点  则输出该节点值
		if (curr->right == nullptr || pre == curr->right) {
			mystack.pop();
			ans.push_back(curr->val);
			pre = curr;
			curr = NULL;
		}
		else {
			curr = curr->right;
			pre = NULL;
		}
	}
	return ans;
}

