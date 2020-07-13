// 最长公共子串,
class Solution3 {
public:
        int LongestCommonSubstr(string str1, string str2) {
               if (str1.size() == 0 && str2.size() != 0) return 0;
               if (str1.size() != 0 && str2.size() == 0) return 0;
               int n = str1.size();
               int m = str2.size();
               int res = 0;
               vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));  // dp[i][j] 表示  str1[:i] 和 str2[:j] 的公共子串长度
               for (int i = 0; i <= n; i++) { // base case
                       dp[i][0] = 0;
               }
               for (int j = 0; j <= m; j++) {
                       dp[0][j] = 0;
               }
               for (int i = 1; i <= n; i++) {
                       for (int j = 1; j <= m; j++) {
                              if (str1[i - 1] == str2[j - 1]) {
                                      dp[i][j] = dp[i - 1][j - 1] + 1;
                                      res = max(dp[i][j], res); // 更新最大值
                              }
                              else { // 不相等的情况
                                      dp[i][j] = 0;
                              }
                       }
               }
               return res;
        }
};