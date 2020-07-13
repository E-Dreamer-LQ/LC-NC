#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// 求数组中每个数的下一个比其大的数的位置，如果没有返回-1
class Solution {
public:
        vector<int> next_greater_element(vector<int> nums) {
               // 使用单调栈解决
               stack<int> sta;
               vector<int> res(nums.size());
               for (int i = nums.size()-1; i >= 0; i--) {
                       while (!sta.empty() && nums[i] >= sta.top()) {
                              sta.pop();
                       }
                       res[i] = sta.empty() ? -1 : sta.top();
                       sta.push(nums[i]);
               }
               return res;
        }
};