#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1) {
            return 0;
        }
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];   // 这里不能使用INT_MIN
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
        
    }
};
// 优化版本
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       int dp_i_0 = 0, dp_i_1 = INT_MIN;
       for (int i = 0; i < n; i++) {
           int temp = dp_i_0;
           dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
           dp_i_1 = max(dp_i_1, temp - prices[i]);
       }
       return dp_i_0;
    }
};