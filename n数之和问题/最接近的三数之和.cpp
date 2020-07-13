
/*
给定一个包括n个整数的数组mums和一个目标值 target.找出nums中的三个整
数，使得它们的和与 target最接近。返回这三个数的和。假定每组输入只存在唯一答案
*/

class Solution {
public:
        int threeSumClosest(vector<int> nums, int target) {
               sort(nums.begin(), nums.end());
               int ans = nums[0] + nums[1] + nums[2];
               for (int i = 0; i < nums.size(); i++) {
                       int start = i + 1, end = nums.size() - 1;
                       while (start < end) {
                              int sum = nums[start] + nums[end] + nums[i];
                              if (abs(target - sum) < abs(target - ans))// sum 与目标  target 的距离，如果相比前面更近则更新结果 ans
                                      ans = sum;
                              if (sum > target)
                                      end--;
                              else if (sum < target)
                                      start++;
                              else  // 最小就是0了
                                      return ans;
                       }
               }
               return ans;
        }
};