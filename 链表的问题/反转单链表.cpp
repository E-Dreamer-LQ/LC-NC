#include <iostream>
using namespace std; 
// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
        ListNode* reverseList(ListNode* head) {
               if (head == nullptr) { return head; }
               ListNode* pNode = head;
               ListNode* pPrev = nullptr;
               while (pNode) {
                       ListNode* pNext = pNode->next;
                       pNode->next = pPrev;  
                       pPrev = pNode;  // pPrev 后移
                       pNode = pNext;  //  pNode 后移
               }
               return pPrev;
        }
                // 递归
        ListNode* reverseList_recursion(ListNode* head) {
               if (head == nullptr || head->next == nullptr) return head;
               ListNode* p = reversedList(head->next);
               head->next->next = head;
               head->next = nullptr;
               return p;
        }
};
