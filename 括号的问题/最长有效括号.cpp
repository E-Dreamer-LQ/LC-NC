#include<bits/stdc++.h> 
using namespace std; 

//  方法一 时间复杂度O(n) + 时间复杂度O（n)
class Solution {
public:
        int longestValidParentheses(string s) {
               int max_length = 0;
               vector<int> dp(s.size());
               for (int i = 1; i < s.size(); i++) {
                       if (s[i] == ')') {
                              if (s[i - 1] == '(') {
                                      if (i >= 2) {
                                             dp[i] = dp[i - 2] + 2;
                                      }
                                      else {
                                             dp[i] = 0 + 2;
                                      }
                              }
                              else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                                      if (i - dp[i - 1] >= 2) {
                                             dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] +  2;
                                      }
                                      else {
                                             dp[i] = dp[i - 1] + 0 + 2;
                                      }
                              }
                              max_length = max(max_length, dp[i]);
                       }
               }
               return max_length;
        }
};

// 方法二
class Solution {
public:
        int longestValidParentheses(string s) {
               int max_length = 0;
               stack<int> sta;
               sta.push(-1);
               for (int i = 0; i < s.size(); i++) {
                       if (s[i] == '(') {
                              sta.push(i);
                       }
                       else {
                              sta.pop();
                              if (sta.empty()) {
                                      sta.push(i);
                              }
                              else {
                                      max_length = max(max_length, i - sta.top());
                              }
                       }
               }
               return max_length;
        }
};


// 方法二： 使用栈，时间复杂度O(n) + 空间复杂度O(n)
class Solution {
public:
        int longestValidParentheses(string s) {
               int max_length = 0;
               stack<int> sta;
               sta.push(-1);
               for (int i = 0; i < s.size(); i++) {
                       if (s[i] == '(') {
                              sta.push(i);
                       }
                       else {
                              sta.pop();
                              if (sta.empty()) {
                                      sta.push(i);
                              }
                              else {
                                      max_length = max(max_length, i - sta.top());
                              }
                       }
               }
               return max_length;
        }
};

// 方法三：不使用额外空间， 时间复杂度O(n) + 空间复杂度O(1)

class Solution {
public:
        int longestValidParentheses(string s) {
               int max_length = 0;
               int left = 0;
               int right = 0;
               for (int i = 0; i < s.size(); i++) {
                       if (s[i] == '(') {
                              left++;
                       }
                       else {
                              right++;
                       }
                       if (left == right) {
                              max_length = max(max_length, 2 * right);
                       }
                       else if (right >= left) {
                              right = left = 0;
                       }
               }
               left = right = 0;
               for (int i = s.size() - 1; i >= 0; i--) {
                       if (s[i] == ')') {
                              right++;
                       }
                       else {
                              left++;
                       }
                       if (left == right) {
                              max_length = max(max_length, 2 * left);
                       }
                       else if (left >= right) {
                              left = right = 0;
                       }
               }
               return max_length;
        }
};








