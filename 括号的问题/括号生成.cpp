#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std; 

// 方法一：dfs
class Solution {
public:
        vector<string> generateParenthesis(int n) {
               vector<string> res;
               if (n == 0) return res;
               dfs("", 0, 0, n, res);
               return res;
        }
        /**
         * @param curStr 当前递归得到的结果
         * @param left   左括号已经用了几个
         * @param right  右括号已经用了几个
         * @param n      左括号、右括号一共得用几个
         * @param res    结果集
         */
        void dfs(string curStr, int left, int right, int n, vector<string>& res) {
               // 递归终止条件
               if (left == n && right == n) {
                       res.push_back(curStr);
               }
               // 剪枝
               if (left < right) {
                       return;
               }
               if (left < n) {
                       dfs(curStr + "(", left + 1, right, n, res);
               }
               if (right < n) {
                       dfs(curStr + ")", left, right + 1, n, res);
               }
        }
};
// 方法二：动态规划
class Solution {
public:
        vector<string> generateParenthesis(int n) {
               if (n == 0) return {};   
               if (n == 1) return { "()" };
               vector<vector<string>> dp(n + 1);//定义状态 dp[i]：使用 i 对括号能够生成的组合。
               dp[0] = { "" };            // 0组括号时记为None
               dp[1] = { "()" };    //# 1组括号只有一种情况
               for (int i = 2; i <= n; i++) { // # 开始计算i组括号时的括号组合
                       for (int j = 0; j < i; j++) {
                              for (string p : dp[j])     //开始遍历 p q ，其中p+q=i-1 , j  作为索引
                                      for (string q : dp[i - j - 1]) {
                                             string str = "(" + p + ")" + q; //dp[i] = "("  + dp[可能的括号对数] + ")" + dp[剩下的括号对数]
                                             dp[i].push_back(str);
                                      }
                       }
               }
               return dp[n];
        }
};