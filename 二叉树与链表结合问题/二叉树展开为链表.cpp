// 二叉树展开为链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
using namespace std; 


// Definition for a binary tree node.
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void flatten(TreeNode* root) {
		// 使用前序遍历形式
		if (root == nullptr) return;
		TreeNode* temp = root->right; // 保留当前节点的右孩子
		root->right = root->left;    // 将当前节点的左孩子  嫁接到原来右孩子
		root->left = nullptr;  // 将当前结点的左孩子置空
		TreeNode* rightmost = root;    // 去找当前结点的左孩子的最右边节点
		while (rightmost->right != nullptr) {
			rightmost = rightmost->right;
		}
		rightmost->right = temp;
		flatten(root->left);   //  可以注释掉
		flatten(root->right);
	}
};

// 后序遍历
class Solution2 {
public:
	TreeNode* pre = nullptr; 
	void flatten(TreeNode* root) {
		if (root == nullptr) return; 
		flatten(root->right); 
		flatten(root->left); 
		// 当前结点 right 指向 上一个结点
		root->right = pre; 
		root->left = nullptr; // 左子树置空
		// 更新上一个结点
		pre = root; 
	}
};



