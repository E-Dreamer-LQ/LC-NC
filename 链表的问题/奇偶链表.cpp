
#include<iostream>
using namespace std;

/*
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:
输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
示例 2:

输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL
*/


// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution{
public:
    ListNode*oddEvenList(ListNode* head){
        if(head ==nullptr)  return nullptr;
        ListNode* odd = head, *even = head->next, *evenHead = head->next;
        while(even !=nullptr&& even->next !=nullptr){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;  // 先拆分成为两个链表，分别包含偶数和奇数
        }
        odd->next = evenHead;   // evenHead用来指向第一个奇数位置的节点
        return head;
    }
};