#include <iostream>
using namespace std;


/*
二、前序遍历
前序遍历与中序遍历相似，代码上只有一行不同，不同就在于输出的顺序。
步骤：
1. 如果当前节点的左孩子cur->left为空，则输出当前节点cur并将其右孩子作为当前节点cur = cur->right。
2. 如果当前节点的左孩子cur->left不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点mostright。
a) 如果前驱节点的右孩子 mostright->right 为空，将它的右孩子设置为当前节点。输出当前节点（在这里输出，这是与中序遍历唯一一点不同）。当前节点更新为当前节点的左孩子。
b) 如果前驱节点的右孩子为当前节点(mostright->right = cur) ，将它的右孩子重新设为空 (mostright->right = nullptr)。当前节点更新为当前节点的右孩子， 即 cur = cur->right。
3. 重复以上1、2直到当前节点为空。
*/

struct TreeNode {
        int val;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        TreeNode(int data):val(data),left(nullptr),right(nullptr){}
};
//前序遍历
void morrisPre(TreeNode* head) {
        if (head == nullptr) return;
        TreeNode* cur = head;
        TreeNode* mostright = nullptr;
        while (cur != nullptr) {
               mostright = cur->left;
               if (mostright != nullptr) {
                       while (mostright->right != nullptr && mostright->right != cur) {
                              mostright = mostright->right;
                       }
                       if (mostright->right != nullptr) {
                              cout << cur->val << endl;
                              mostright->right = cur;
                              cur = cur->left;
                       }
                       else {
                              mostright->right = nullptr;
                       }
               }
               else {
                       cout << cur->val << endl;
               }
               cur = cur->right;
        }
        return;
}