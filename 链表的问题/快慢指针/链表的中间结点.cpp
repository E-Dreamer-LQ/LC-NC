#include <iostream>
//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
// 方法一: 快慢指针法
class Solution {
public:
        ListNode* middleNode(ListNode* head) {
               ListNode* slow = head;
               ListNode* fast = head->next;
               while (fast != nullptr && fast->next != nullptr) {
                       slow = slow->next;
                       fast = fast->next->next;
               }
               return slow;
        }
};