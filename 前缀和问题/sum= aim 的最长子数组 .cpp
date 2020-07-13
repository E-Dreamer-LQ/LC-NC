#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// sum = aim 的最长子数组（全正数）
int main() {
        int aim;
        int n;
        while (~scanf_s("%d%d", &n, &aim)) {
               vector<int> nums(n);
               for (int i = 0; i < n; i++) {
                       scanf_s("%d", &nums[i]);
               }
               if (n == 0) cout << 0;
               int l = 0;
               int r = 0;
               int len = 0;
               int sum = nums[0];
               while (r < nums.size()) {
                       if (aim == sum) {  // 更新
                              len = max(len, r - l + 1);
                              sum -= nums[l++];  // 因为
                       }
                       else if (sum < aim) {
                              r++;  // 向右边扩
                              if (r == nums.size()) { // 保证不越界
                                      break;
                              }
                              sum += nums[r];
                       }
                       else {
                              sum -= nums[l++]; // 往左边缩
                       }
               }
               return len;
        }
}
// sum<=aim的最长子数组（任意数）
class Solution {
public:
        int maxlengthAwesome(vector<int> arr, int aim) {
               if (arr.size() == 0) return 0;
               vector<int> sum(arr.size());
               vector<int> ends(arr.size());
               sum[arr.size() - 1] = arr[arr.size() - 1];
               ends[arr.size() - 1] = arr.size() - 1;
               // sum数组和 min_sum_index数组生成过程
               for (int i = arr.size() - 2; i >= 0; i--) { // 从右往左算
                       if (sum[i + 1] < 0) { // 当前位置往往右扩能让累加和变得更小
                              sum[i] = arr[i] + sum[i + 1];
                              ends[i] = ends[i + 1];
                       }
                       else { // 否则累加和就是当前位置的 arr[i] ， 右边界就是自己
                              sum[i] = arr[i];
                              ends[i] = i;
                       }
               }
               int R = 0;  // 扩的右边界
               int sum_val = 0;
               int len = 0;
               // 从开头开始扩
               for (int start = 0; start < arr.size(); start++) {
                       while (R < arr.size() && sum_val + sum[R] <= aim) { // 不越界并且  不超过aim
                              sum_val += sum[R];  
                              R = ends[R] + 1;
                       }
                       sum_val -= R > start ? arr[start] : 0;  // 如果 sum_val 大于R 则减掉当前 arr[start] ，否则扩的窗口为空（没扩动），减去0         
                       len = max(len, R - start);
                       R = max(R, start + 1); // 扩不出去，更新R位置
               }
               return len;
        }
};

