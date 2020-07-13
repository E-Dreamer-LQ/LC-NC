/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/

/*
编程思想： 
1.判断两个链表是否是环形链表（快慢指针法）
2.三种情况： 
    a.两个链表都是无环链表，进入noloop 函数，求出两个链表的长度，让其中一个先走多余的长度，然后走到相等时就是第一个公共结点
    b.
*/
class Solution {
public:
    // 长短指针
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr || pHead2 == nullptr ){
            return nullptr;
        }
        ListNode* loop1 = getLoopNode(pHead1);
        ListNode* loop2 = getLoopNode(pHead2);
        if (loop1 == nullptr && loop2 == nullptr){
            return noLoop(pHead1,pHead2);
        }
        if (loop1 != nullptr && loop2 != nullptr){
            return bothLoop(pHead1,loop1,pHead2,loop2);
        }
        return nullptr;
    }
    
    ListNode* getLoopNode(ListNode* head){
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
            return nullptr;
        }
        // 快慢指针求交点
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        while(fast != slow){
            if (fast->next == nullptr || fast->next->next == nullptr){
                return nullptr;
            }
            fast = fast->next->next;
            slow = fast->next;
        }
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* noLoop(ListNode* head1,ListNode* head2){
        if (head1 == nullptr || head2 == nullptr){
            return nullptr;
        }
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;
        int n = 0;
        while(cur1->next != nullptr){
            n++;
            cur1 =cur1->next;
        }
        while(cur2->next != nullptr){
            n--;
            cur2 = cur2->next;
        }
        if(cur1 != cur2){
            return nullptr;
        }
        if (n>0){
             cur1 = head1;
            }
        else{
            cur1 = head2;}
        cur2 = cur1 == head1 ? head2 : head1;
        n = abs(n);
        while(n!= 0){
            n--;
            cur1 = cur1->next;
        }
        while(cur1 != cur2){
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
    
    ListNode* bothLoop(ListNode* head1,ListNode* loop1,ListNode* head2,ListNode* loop2){
        ListNode* cur1 = nullptr;
        ListNode* cur2 = nullptr;
        if(loop1 == loop2){  // noLoop 型
            cur1 = head1;
            cur2 = head2;
            int n=0;
            while(cur1 != loop1){
                n++;
                cur1 = cur1->next;
            }
            while(cur2 != loop2){
                n--;
                cur2 = cur2->next;
            }
            if (n>0){
                cur1 = head1;
            }
            else{
                cur1 = head2;}
            cur2 = cur1 == head1 ? head2 : head1;
            n = abs(n);
            while(n != 0){
                n--;
                cur1 = cur1->next;
            }
            while(cur1 != cur2){
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return cur1;
        }
        else{
            cur1 = loop1->next;
            while(cur1 != loop1){
                if (cur1 == loop2){
                    return loop1;
                }
                cur1 = cur1->next;
            }
            return nullptr;
        }
    }
};