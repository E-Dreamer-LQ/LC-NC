#Include<iostream>
using namespace std; 

/*
题目要求： 
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead==nullptr || pHead->next==nullptr){return pHead;}
        ListNode* Head = new ListNode(0); // 防止第一个就和第二个相同了
        Head->next = pHead;
        ListNode* pre  = Head;
        ListNode* last = Head->next;
        while (last!=nullptr){
            if(last->next!=nullptr  && last->val == last->next->val){
                // 找到最后的一个相同节点
                while (last->next!=nullptr  && last->val == last->next->val){
                    last = last->next;
                }
                pre->next = last->next;
                last = last->next;
            }else{
                pre = pre->next;
                last = last->next;
            }
        }
        return Head->next;


    }
};