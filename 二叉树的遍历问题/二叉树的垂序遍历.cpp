#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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
	 map<int, vector<pair<int, int>>> tree;
	 void dfs(TreeNode* root, int x, int y) {
		 if (root == nullptr)  return;
		 tree[x].push_back(make_pair(y, root->val));
		 dfs(root->left, x - 1, y + 1);   // 将节点进行给予坐标处理
		 dfs(root->right, x + 1, y + 1);
	 }

	 vector<vector<int>> verticalTraversal(TreeNode* root) {
		 vector<vector<int>> res;
		 if (root == nullptr) return res;
		 dfs(root, 0, 0);
		 for (auto& node : tree) {    // 由于要修改node的值，需要加引用
			 sort(node.second.begin(), node.second.end());
			 vector<int> tmp;
			 for (auto t : node.second) {
				 tmp.push_back(t.second);   // 获取val
			 }
			 res.push_back(tmp);
		 }
		 return res;
	 }
 };