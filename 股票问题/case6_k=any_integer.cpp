/*
一次交易由买入和卖出构成，至少需要两天。所以说有效的限制 k 应该不超过 n/2，
如果超过，就没有约束作用了，相当于 k = +infinity。这种情况是之前解决过的。
*/

class Solution {
public:
    int maxProfit(int max_k, vector<int>& prices) {
        int n = prices.size();
        if (max_k > n / 2) // k属于 无穷， 一定要，不然出错
            return maxProfit_k_inf(prices);
        vector<vector<vector<int> > > dp(n, vector<vector<int>>(max_k+1, vector<int>(2))); // dp[n][max_k+1][2]
        for (int i = 0; i < n; i++)
            for (int k = max_k; k >= 1; k--) {
                if (i - 1 == -1) {
                    /* 处理 base case */
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[i];
                    continue;
                }
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        return dp[n - 1][max_k][0];
    }
    int maxProfit_k_inf(vector<int> prices) {
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


