#include<iostream> 
#include <cstring>
#include <algorithm>
using namespace std; 
// 类似 归并排序
class Solution3 {
public:
        ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
        {
               if (!pHead1)
                       return pHead2;
               if (!pHead2)
                       return pHead1;
               ListNode* Head;
               ListNode* p;
               //取较小值作头结点
               if (pHead1->val <= pHead2->val) {
                       Head = pHead1;
                       pHead1 = pHead1->next;
               }
               else {
                       Head = pHead2;
                       pHead2 = pHead2->next;
               }
               //开始遍历合并
               p = Head;                      //p为合并后的链表的工作指针
               while (pHead1 && pHead2) {                       //当有一个链表到结尾时，循环结束
                       if (pHead1->val <= pHead2->val) {          //如果链表1的结点小于链表2的结点
                              p->next = pHead1;                            //取这个结点加入合并链表
                              pHead1 = pHead1->next;                 //链表1后移一位
                              p = p->next;                                      //工作指针后移一位
                       }
                       else {                                               //否则取链表2的结点
                              p->next = pHead2;
                              pHead2 = pHead2->next;
                              p = p->next;
                       }
               }
               if (pHead1 == NULL)           //链表1遍历完了
                       p->next = pHead2;         //如果链表2也遍历完了，则pHead2=NULL
               if (pHead2 == NULL)            //链表2遍历完了
                       p->next = pHead1;         ///如果链表1也遍历完了，则pHead1=NULL
               return Head;
        }
};
// 使用递归法
class Solution2 {
public:
        ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
        {
               if (pHead1 == NULL) return pHead2;
               if (pHead2 == NULL) return pHead1;
               ListNode* mergeList = NULL;
               if (pHead1->val < pHead2->val) {
                       mergeList = pHead1;
                       mergeList->next = Merge(pHead1->next, pHead2);
               }
               else {
                       mergeList = pHead2;
                       mergeList->next = Merge(pHead1, pHead2->next);
               }
               return mergeList;
        }
};