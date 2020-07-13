#include<iostream>
#include <string>
using namespace std 


// 最长回文子序列   动态规划dp
class Solution2 {
public:
        int LongestpalindromeSubSequence(string s) {
               if (s.size() == 0) return 0;
               int n = s.size();
               vector<vector<int>> dp(n, vector<int>(n, 0));
               //base case
               for (int i = 0; i < s.size(); i++) {
                       dp[i][i] = 1;
               }
               // 状态转移
               for (int i = n - 1; i >= 0; i++) {
                       for (int j = i + 1; j < n; j++) {
                              if (s[i] == s[j]) {
                                      dp[i][j] = dp[i + 1][j - 1] + 2;
                              }
                              else {
                                      dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                              }
                       }
               }
               return dp[0][n - 1];  // 最长回文子串长度
        }
};