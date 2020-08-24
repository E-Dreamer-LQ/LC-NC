#include <iostream>
#include <vector>
using namespace std;
// 给定一个排序数组，在原地删除重复出现的元素，使得元素之出现一次，返回移除后数组的新长度
class Solution {
public:
        int removeduplicates(vector<int> nums) {
               int n = nums.size();
               int slow = 0;
               int fast = 1;
               while (fast < n) {
                       if (nums[slow] != nums[fast]) {
                              slow++;
                              // 维护nums[0...slow]无重复
                              nums[slow] = nums[fast];
                       }
                       fast++;
               }
               // 长度索引为+1
               return slow + 1;
        }
};
struct ListNode*
{
        int val;
        ListNode* next;
        ListNode* (int x) :val(x), next(nullptr) {};
};
// 可以拓展到链表
class Solution2 {
        ListNode* deleteDuplicate(ListNode* head) {
               if (head == 0) return nullptr;
               ListNode* slow;
               ListNode* fast = head->next;
               while (fast != nullptr) {
                       if (fast->val != slow->val) {
                              slow->next = fast; // nums[slow] = nums[fast]
                              slow = slow->next; // slow++
                       }
                       fast = fast->next;
               }
               // 断开与后面重复元素的连接
               slow->next = nullptr;
               return head;
        }
};

