// 最长公共子序列
class Solution4 {
public:
        int LongCommonSubSequence(string str1, string str2) {
               int n = str1.size();  
               int m = str2.size();
               vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));  // dp[i][j]  代表  str1[0:i] 和 str2[0:j] 的 公共子序列长度
               for (int i = 1; i <= n; i++) {
                       for (int j = 1; j <= m; j++) {
                              if (str1[i] == str2[j]) {
                                      dp[i][j] = dp[i - 1][j - 1] + 1;
                              }
                              else {
                                      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 要么在 s[i-1 : j] 取得，要么在 s[i : j-1]取得
                              }
                       }
               }
               return dp[n][m];
        }
};