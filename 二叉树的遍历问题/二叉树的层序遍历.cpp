#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//Definition for a binary tree node.
 struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 //  BFS 
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr) return res;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			vector<int> level;
			while (size--) {
				TreeNode* temp = que.front();
				que.pop();
				level.push_back(temp->val);
				if (temp->left != nullptr) que.push(temp->left);
				if (temp->right != nullptr) que.push(temp->right);

			}
			res.push_back(level);
		}
		return res;
	}
};

