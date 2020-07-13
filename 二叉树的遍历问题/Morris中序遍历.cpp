#include <iostream>
using namespace std;


/*
一、中序遍历步骤：
1. 来到当前节点cur, 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点, 即cur = cur->right。
2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点, 即找到当前节点左子树上的最右节点，记为mostRight
a) 如果mostRight的右孩子为空，将它的右孩子设置指向为当前节点cur。当前节点更新为当前节点的左孩子, 即cur = cur->left。
b) 如果mostRight的右孩子为当前节点cur，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子， 即cur = cur->right。
3. 重复以上1、2直到当前节点为空。
*/

struct TreeNode {
        int val;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        TreeNode(int data):val(data),left(nullptr),right(nullptr){}
};
// morris中序遍历
void morrisIn(TreeNode* head) {
        if (head == nullptr) {
               TreeNode* cur = head;
               TreeNode* mostright = nullptr;
               while (cur) {
                       mostright = cur->left; // cur 的左子树的最右的结点
                       if (mostright != nullptr) {
                              while (mostright->right != nullptr && mostright->right !=  cur) {
                                      mostright = mostright->right;
                              }
                              // 如果 mostright 的右孩子为空，当前节点cur更新为cur->left
                              if (mostright->right == nullptr) {
                                      mostright->right = cur;
                                      cur = cur->left;
                                      continue;
                              }
                              // 如果mostright 的右孩子不为空，则置mostright->right 为空
                              else {
                                      mostright->right = nullptr;
                              }
                       }
                       cout << cur->val << endl;
                       cur = cur->right;
               }
        }
        return;
}