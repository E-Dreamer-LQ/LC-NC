#include<iostream>
#include <string>
using namespace std 

// 最长回文子串 (O(N^2) + O(N)) ,     // 中心扩展法
class Solution1 {
public:
        string palindrome(string str, int left, int right) {
               while (left >= 0 && right <= str.size() ) {
                       if (str[left] == str[right]) {
                              left--;
                              right++;
                       }
               }
               return str.substr(left + 1, right-left+1);
        }
        string  LongPalindromeSubstr(string str) {
               string res;
               if (str.size() == 0) return res;
               for (int i = 0; i < str.size(); i++) {
                       string s1 = palindrome(str, i, i);
                       string s2 = palindrome(str, i, i + 1);
                       res = s1.size() > res.size() ? s1 : res;
                       res = s2.size() > res.size() ? s2 : res;
               }
               return res;
        }
};
// 最长回文子串 (O(N^2) + O(N)) ,     // 动态规划法
//我们将f[i][j]表述为从j到i的子串为回文串，j <= i，
//此时dp的矩阵为左下三角！如果a[i]==a[j]且f[i-1][j+1]=true, 那么f[i][j]也为true。
//需要注意一点：当i - j < 2时，如果s[i] = s[j]，
//那么f[i][j]必为true，即单个字符或者两个相邻相同字符为回文子串。
class Solution11 {
public:
        string LongPalindromeSubstr(string s) {
               int n = s.length();
               if (n == 0) return "";
               string res = "";
               vector<vector<bool>> dp(n, vector<bool>(n, false));
               int maxlen = 0;
               int curlen = 0;
               for (int i = 0; i < n; i++) {
                       for (int j = 0; j <= i; j++) {   // dp[0][0]=true, 一定成立
                              if ((s[i] == s[j]) && ((i - j < 2) || (i > 0 && dp[i - 1][j  + 1]))) {
                                      dp[i][j] = true;
                                      curlen = i - j + 1;
                                      if (curlen > maxlen) {
                                             maxlen = curlen;
                                             res = s.substr(j, curlen);
                                      }
                              }
                       }
               }
               return res;
        }
};