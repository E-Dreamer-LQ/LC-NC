#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//每日温度
class Solution {
public:
        vector<int> daily_temperate(vector<int> nums) {
               // 跟上面类似
               stack<int> sta;
               int n = nums.size();
               vector<int> res(n);
               for (int i = n - 1; i >= 0; i--) {
                       while (!sta.empty() && nums[i] >= nums[sta.top()]) {
                              sta.pop();
                       }
                       res[i] = sta.empty() ? -1 : sta.top() - i;
                       sta.push(i);
               }
               return res;
        }
};

