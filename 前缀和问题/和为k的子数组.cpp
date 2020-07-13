#include <iostream>
#include<vector>
#include <map>
#include <unordered_map>
using namespace std;
// 使用前缀和
class Solution {
public:
        int subarraySum(vector<int>& nums, int k) {
               //先求出前缀和
               vector<int> sums(nums.size() + 1, 0);
               for (int i = 1; i <= nums.size(); ++i) {
                       sums[i] = sums[i - 1] + nums[i - 1];
               }
               int counter = 0;
               for (int i = 0; i < sums.size(); ++i) {
                       for (int j = i + 1; j < sums.size(); ++j) {
                              if (sums[j] - sums[i] == k) {
                                      counter++;
                              }
                       }
               }
               return counter;
        }
};
/*
遍历数组nums，计算从第0个元素到当前元素的和，用哈希表保存出现过的累积和sum的次数。
如果sum - k在哈希表中出现过，则代表从当前下标i往前有连续的子数组的和为sum。
时间复杂度为$O(n)$，空间复杂度为$O(n)$。
*/
class Solution {
public:
        int subarraySum(vector<int>& nums, int k) {
               int sum = 0, res = 0;
               unordered_map<int, int> cul;
               cul[0] = 1;
               for (auto& m : nums) {
                       sum += m;
                       res += cul[sum - k];
                       cul[sum]++; // 哈希表保存出现过的累积和sum的次数
               }
               return res;
        }
};

