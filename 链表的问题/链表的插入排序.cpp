#include<iostream> 
using namespace std ; 

/*
首先判断两个相邻节点的大小，如果head->val > head->next->val，
则需要将head->next->val插入到从dummy节点开始遍历第一个大于head->next->val节点的前面！
好好理解这句话！在进行插入的时候，首先使用cur指针标记head->next节点，
并改变head->next的指向。从而将待插入节点分离！接着就是普通的插入操作了！
*/
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
        ListNode* insertionSortList(ListNode* head) {
               if (head == nullptr || head->next == nullptr) return head;// 必须判断head->next
               ListNode* dummy = new ListNode(0), * pre = nullptr;
               dummy->next = head;
               while (head->next != nullptr) {
                       if (head->val <= head->next->val) {  // 无需进行插入操作
                              head = head->next;
                              continue;
                       }
                       pre = dummy;
                       while (pre->next->val < head->next->val) {
                              pre = pre->next;
                       }
                       ListNode* cur = head->next;
                       head->next = cur->next;
                       cur->next = pre->next;
                       pre->next = cur;
               }
               return dummy->next;
        }
};

