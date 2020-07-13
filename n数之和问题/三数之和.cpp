
/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/


class Solution {
public:
        vector<vector<int>> threeSum(vector<int>& nums) {
               vector<vector<int>> res;
               if (nums.size() == 0) {
                       return res;
               }
               sort(nums.begin(), nums.end());
               for (int i = 0; i < nums.size(); i++) {
                       if (i > 0 && nums[i] == nums[i - 1]) continue;
                       int target = -nums[i];
                       int j = i + 1;
                       int k = nums.size() - 1;
                       while (j < k) {
                              if (nums[j] + nums[k] == target) {
                                      vector<int> cur;
                                      cur.push_back(nums[i]);
                                      cur.push_back(nums[j]);
                                      cur.push_back(nums[k]);
                                      res.push_back(cur);
                                      j++;
                                      k--;
                                      while (j < nums.size() && nums[j] == nums[j - 1])  j++;
                                      while (k > j && nums[k] == nums[k + 1]) k--;
                              }
                              else if (nums[j] + nums[k] > target) {
                                      k--;
                              }
                              else {
                                      j++;
                              }
                       }
               }
               return res;
        }
};

