// 最长上升子序列  , 动态规划 O(n^2)
class Solution6 {
public:
        int LongestUpSubstr(vector<int> str) {
               if (str.size() == 0) return 0;
               int n = str.size();
                // dp[i] 代表dp[i] 表⽰以 str[i] 这个数结尾的最⻓递增⼦序列 的⻓度
               vector<int> dp(n, 1);
               for (int i = 0; i < n; i++) {
                       for (int j = 0; j < i; j++) {
                              if (str[i] > str[j]) {
                                      dp[i] = max(dp[i], dp[j] + 1);
                              }
                       }
               }
               int res = dp[0];
               for (int i = 1; i < n; i++) {
                       res = max(res, dp[i]);
               }
               return res;
        }
};


// 使用二分法优化 版本
/*
作者：liweiwei1419
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }
        vector<int> tail; //  tail 数组的定义：长度为 i + 1 的上升子序列的末尾最小是几
        tail.push_back(nums[0]);// 遍历第 1 个数，直接放在有序数组 tail 的开头
        // tail 结尾的那个索引
        int end = 0;

        for (int i = 1; i < len; ++i) {
            if (nums[i] > tail[end]) { //逻辑1：比 tail 数组实际有效的末尾的那个元素还大
                tail.push_back(nums[i]); // 直接添加在那个元素的后面，所以 end 先加 1
                end++;
            } else {
                // 使用二分查找法，在有序数组 tail 中
                // 找到第 1 个大于等于 nums[i] 的元素，尝试让那个元素更小
                int left = 0;
                int right = end;
                while (left < right) {
                     // 选左中位数不是偶然，而是有原因的，原因请见 LeetCode 第 35 题题解
                     // int mid = left + (right - left) / 2;
                    int mid = (left + right) >> 1;  // 右移一位等于 除2了
                    if (tail[mid] < nums[i]) {
                         // 中位数肯定不是要找的数，把它写在分支的前面
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                    // 走到这里是因为 【逻辑 1】 的反面，因此一定能找到第 1 个大于等于 nums[i] 的元素
                    // 因此，无需再单独判断
                tail[left] = nums[i];
            }
        }
          // 此时 end 是有序数组 tail 最后一个元素的索引
          // 题目要求返回的是长度，因此 +1 后返回
        return end + 1;
    }
};
