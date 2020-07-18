/*
输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。  
*/


#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
        int val;
        struct TreeNode *left;
        struct TreeNode *right;
        TreeNode(int x) :
                       val(x), left(NULL), right(NULL) {
        }
};
class Solution {
public:
        vector<vector<int> > res;
        vector<int> temp;
        vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
               if (root == NULL)
                       return res;
               temp.push_back(root->val); // 放到 判断是否达到 叶子节点的前面，首先需要加入元素
               if ((expectNumber - root->val) == 0 && root->left == NULL && root->right ==  NULL) // 到最后一个叶节点
               {
                       res.push_back(temp);
               }
               FindPath(root->left, expectNumber - root->val);
               FindPath(root->right, expectNumber - root->val);
               if (temp.size() != 0)
                       temp.pop_back();
               //删除temp的最后一个元素，它表示当前叶节点和根节点形成的路径不满足条件，删除叶节点，返回它的父节点
               return res;
        }
};

