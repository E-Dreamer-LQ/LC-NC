// newcoder-二叉搜索树与双向链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>
using namespace std; 


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

// 原先指向左子结点的指针调整为链表中指向前一个结点的指针，原先指向右子结点的指针调整为链表中指向下一个结点的指针。
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr) return nullptr;
		stack<TreeNode*> sta;
		TreeNode* cur = pRootOfTree; 
		TreeNode* pre = nullptr;
		bool isfirst = true; 
		while (cur || !sta.empty()) {
			while (cur) {
				sta.push(cur);
				cur = cur->left; 
			}
			cur = sta.top();
			sta.pop();
			if (isfirst) {
				pRootOfTree = cur;  // 将中序遍历序列中的第一个节点记为root
				pre = pRootOfTree;
				isfirst = false; 
			}
			else {
				pre->right = cur;   // 上个结点的right -> cur 
				cur->left = pre;   //   意思是当前节点的left -> pre
				pre = cur; 
			}
			cur = cur->right; 
		}
		return pRootOfTree; 

	}
};

// 递归版本
class Solution2 {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr) return nullptr;

		// 双向链表尾节点
		TreeNode* list_last = nullptr;

		// 递归建立双向链表
		ConvertNode(pRootOfTree, list_last);

		// 查找双向链表首节点
		while (list_last->left != nullptr)
		{
			list_last = list_last->left;
		}

		// 返回双向链表的首节点
		return list_last;
	}

	// 对BST中序遍历，得到有序序列；调整序列元素的指针，将有序序列调整为双向链表
	void ConvertNode(TreeNode* cur, TreeNode*& list_last) // 注意形参
	{
		// 边界条件(递归出口)
		if (cur == nullptr) return;

		// 遍历左子树
		if (cur->left != nullptr) ConvertNode(cur->left, list_last);

		// 建立双向链接
		cur->left = list_last;                           // 单侧链接， 当前节点的left -> 上个结点
		if (list_last != nullptr) list_last->right = cur; // 单侧链接   上个结点的right -> 当前节点
		list_last = cur;    // 更新上个节点

		//遍历右子树
		if (cur->right != nullptr) ConvertNode(cur->right, list_last);
	}
};

/*
链接：https://www.nowcoder.com/questionTerminal/947f6eb80d944a84850b0538bf0ec3a5?f=discussion
来源：牛客网

中序遍历即可。只需要记录一个pre指针即可。
高分答案也太绕了吧

class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if(pRootOfTree == nullptr) return nullptr;
		TreeNode* pre = nullptr;

		convertHelper(pRootOfTree, pre);

		TreeNode* res = pRootOfTree;
		while(res ->left)
			res = res ->left;
		return res;
	}

	void convertHelper(TreeNode* cur, TreeNode*& pre)
	{
		if(cur == nullptr) return;

		convertHelper(cur ->left, pre);

		cur ->left = pre;
		if(pre) pre ->right = cur;
		pre = cur;

		convertHelper(cur ->right, pre);

	}
};
*/