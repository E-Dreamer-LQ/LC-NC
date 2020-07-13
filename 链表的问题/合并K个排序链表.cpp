#include <iostream>
using namespace std;

// 使用最小堆， 时间复杂度O(Nlogk)，空间复杂度O(N）
class Solution {
public:
      // 小根堆的回调函数
      struct cmp {
              bool operator()(ListNode* a, ListNode* b) {
                     return a->val > b->val;
              }
      };
     ListNode* mergeKLists(vector<ListNode*>& lists) {
             priority_queue<ListNode*, vector<ListNode*>, cmp> pri_queue;
             // 建立大小为k的小根堆
             for (auto it : lists) {
                    if (it) pri_queue.push(it);
             }
             // 可以使用哑节点/哨兵节点
             ListNode* dummy = new ListNode(-1);
             ListNode* p = dummy;
             // 开始出队
             while (!pri_queue.empty()) {
                    ListNode* top = pri_queue.top();
                    pri_queue.pop();
                    p->next = top;
                    p = top;
                    if (top->next) pri_queue.push(top->next);
             }
             return dummy->next;
     }
};
// 使用两两合并，时间复杂度O(NK)，空间复杂度O(1）
class Solution {
public:
       // 合并两个有序链表
       ListNode* merge(ListNode* p1, ListNode* p2) {
              if (!p1) return p2;
              if (!p2) return p1;
              if (p1->val <= p2->val) {
                      p1->next = merge(p1->next, p2);
                      return p1;
              }
              else {
                      p2->next = merge(p1, p2->next);
                      return p2;
              }
       }
       ListNode* mergeKLists(vector<ListNode*>& lists) {
              if (lists.size() == 0) return nullptr;
              ListNode* head = lists[0];
              for (int i = 1; i < lists.size(); ++i) {
                      if (lists[i]) head = merge(head, lists[i]);
              }
              return head;
       }
};
// 类似于归并排序的分而治之 ,时间复杂度O(Nlogk)，空间复杂度O(1）
class Solution {
public:
       // 合并两个有序链表
       ListNode* merge_process(ListNode* p1, ListNode* p2) {
              if (!p1) return p2;
              if (!p2) return p1;
              if (p1->val <= p2->val) {
                      p1->next = merge(p1->next, p2);
                      return p1;
              }
              else {
                      p2->next = merge(p1, p2->next);
                      return p2;
              }
       }
       ListNode* merge(vector<ListNode*>& lists, int start, int end) {
              if (start == end) return lists[start];
              int mid = (start + end) / 2;
              ListNode* l1 = merge(lists, start, mid);
              ListNode* l2 = merge(lists, mid + 1, end);
              return merge_process(l1, l2);
       }
       ListNode* mergeKLists(vector<ListNode*>& lists) {
              if (lists.size() == 0) return nullptr;
              return merge(lists, 0, lists.size() - 1);
       }
};

