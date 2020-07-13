#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
               ListNode* dummy = new ListNode(0);
               dummy->next = head;
               int length = 0;
               ListNode* first = head;
               while (first != nullptr) {
                       length++;
                       first = first->next;
               }
               length -= n;
               first = dummy;
               while (length > 0) {
                       length--;
                       first = first->next;
               }
               first->next = first->next->next;
               return dummy->next;
        }
};
// 方法二： 一次遍历,第一个指针从列表的开头向前移动 n+1 步，
//而第二个指针将从列表的开头出发。现在，这两个指针被 n 个结点分开
// first 指针走到尾时，second 和 first间隔n个结点即为倒数第n个结点
class Solution {
public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
               ListNode* dummy = new ListNode(0);
               dummy->next = head;
               ListNode* first = dummy;
               ListNode* second = dummy;
               for (int i = 1; i <= n+1; i++) {
                       first = first->next;
               }
               while (first != nullptr) {
                       first = first->next;
                       second = second->next;
               }
               second->next = second->next->next;
               return dummy->next;
        }
};