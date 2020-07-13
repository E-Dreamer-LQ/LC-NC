#include <iostream>
using namespace std; 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> sta1;
        stack<ListNode*> sta2;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        //ListNode* res = new ListNode(0);
        ListNode* res = nullptr;
        bool carry = false;                
        while (p1 != nullptr) {
            sta1.push(p1);
            p1 = p1->next;
        }
        while (p2 != nullptr) {
            sta2.push(p2);
            p2 = p2->next;
        }
        while (!sta1.empty() || !sta2.empty()) {
            int r1 = sta1.empty() ? 0 : sta1.top()->val;
            int r2 = sta2.empty() ? 0 : sta2.top()->val;
            int sum = r1 + r2 + (carry ? 1 : 0);
            carry = (sum >= 10);         // carry = sum/10     
            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = res;
            res = newNode;
            if (!sta1.empty()) sta1.pop();
            if (!sta2.empty()) sta2.pop();
        }
        if (carry) {
            ListNode* newNode = new ListNode(1);
            newNode->next = res;
            res = newNode;
        }
        return res;
    }
};

