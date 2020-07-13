/*
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/

状态转移问题： 
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
              max(   选择 rest  ,           选择 sell      )

解释：今天我没有持有股票，有两种可能：
要么是我昨天就没有持有，然后今天选择 rest，所以我今天还是没有持有；
要么是我昨天持有股票，但是今天我 sell 了，所以我今天没有持有股票了。

dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
              max(   选择 rest  ,           选择 buy         )

解释：今天我持有着股票，有两种可能：
要么我昨天就持有着股票，然后今天选择 rest，所以我今天还持有着股票；
要么我昨天本没有持有，但今天我选择 buy，所以今天我就持有股票了。
*/ 
#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
        // k =1 的情况
        int maxProfit(vector<int>& prices) {
               if (prices.size() == 0 || prices.size() == 1) {
                       return 0;
               }
               int n = prices.size();
               // dp[i][0] 表示第i天没有股票在手， dp[i][1] 表示第i天有股票在手
               vector<vector<int>> dp(n, vector<int>(2));
               for (int i = 0; i < n; i++) {
                       if (i - 1 == -1) {
                              dp[i][0] = 0;
                              continue;
                       }
                       dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                       dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
               }
               return dp[n - 1][0];
        }
        // 优化版本
        int maxProfit(vector<int>& prices) {
               if (prices.size() == 0 || prices.size() == 1) {
                       return 0;
               }
               int n = prices.size();
               // base case : dp[i][0] = 0， dp[i][1] = -infinity
               int dp_i_0 = 0, dp_i_1 = INT_MIN;
               for (int i = 0; i < n; i++) {
                       dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
                       dp_i_1 = max(dp_i_1, -prices[i]);
               }
               return dp_i_0;
        }
}

