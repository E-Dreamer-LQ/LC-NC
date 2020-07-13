#include <iostream>
using namespace std;
struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
        ListNode* reverseKgroup(ListNode* head, int k) {
               if (head == nullptr) return nullptr;
               ListNode* a;
               ListNode* b;
               a = b = head;
               for (int i = 0; i < k; i++) {
                       // 不足K个，不需要反转，base case
                       if (b == nullptr) return head;
                       b = b->next;
               }
               // 反转前 K个元素
               ListNode* newhead = reverse(a, b);
               // 递归翻转后续链表并连接起来, 每k 个断开一次
                                 //本次翻转后的链表的尾节点连接上下一个待翻转链表的头节点，递归实现
               a->next = reverseKgroup(b, k);
               return newhead;
        }
        ListNode* reverse(ListNode* a, ListNode* b) {
               ListNode* pPrev = nullptr;
               ListNode* pNode = a;
               while (pNode != b) {
                       ListNode* pNext = pNode->next;
                       pNode->next = pPrev;
                       pPrev = pNode;
                       pNode = pNext;
               }
               return pPrev;
        }
};

// 注释
class Solution2 {
    public ListNode reverseKGroup(ListNode head, int k) {
        //递归终止条件，当head为null时中止递归
        if (head == null) {
            return null;
        }
        //根据k寻找待翻转链表的尾
        ListNode end = head;
        for (int i = 0; i < k - 1; i++) {
            end = end.next;
            if (end == null) {
                return head;
            }
        }
        //保存好下次翻转的链表的头
        ListNode nextListNode = end.next;
        //翻转[start , end]范围中的链表，并返回头节点
        ListNode newHead = reverseListNode(head, end);
        //此时head已经变成了链表的尾节点
        //本次翻转后的链表的尾节点连接上下一个待翻转链表的头节点，递归实现
        head.next = reverseKGroup(nextListNode, k);
        return newHead;
    }
    private ListNode reverseListNode(ListNode start, ListNode end) {
        ListNode tmp = null;
        while (tmp != end) {
            ListNode next = start.next;
            start.next = tmp;
            tmp = start;
            start = next;
        }
        return tmp;
    }
}