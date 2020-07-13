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
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack <TreeNode*> sta;
		vector <int> res;
		if (root == nullptr) return res;  // 空树， 直接返回res
		TreeNode* cur = root;
		while (cur != nullptr || !sta.empty) {
			// 先遍历左孩子
			if (cur != nullptr ){
				sta.push(cur);
				cur = cur->left;
			}
			else {
				// 再 是 根结点
				cur = sta.top(); 
				sta.pop();  // 访问完根节点后就可以出栈，左孩子和根节点都访问完
				res.push_back(cur->val);
				// 最后右孩子
				cur = cur->right;
			}
		}
		return res; 
	}
};

