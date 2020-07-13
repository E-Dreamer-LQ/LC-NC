#include <iostream>
using namespace std; 
// 主要考察： 快慢指针求中点位置  和  归并排序过程
class Solution {
public:
         ListNode* sortList(ListNode* head) {
                if (!head || !head->next) return head;
                ListNode* slow = head, * fast = head->next;
                while (fast && fast->next) {
                        slow = slow->next;
                        fast = fast->next->next;
                }
                ListNode* left = sortList(slow->next);
                slow->next = NULL;
                ListNode* right = sortList(head);
                return merge(left, right);
         }
         ListNode* merge(ListNode* left, ListNode* right) {
                ListNode* dummy = new ListNode(0); // 哨兵结点
                ListNode* p = dummy;
                while (left && right) {
                        if (left->val < right->val) {
                               p->next = left;
                               left = left->next;
                        }
                        else {
                               p->next = right;
                               right = right->next;
                        }
                        p = p->next;
                }
                if (left) p->next = left;
                if (right) p->next = right;
                return dummy->next;
         }
};