#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
        bool isValid(string str) {
               // 使用栈结构
               stack<char> left;
               for (auto c : str) {
                       if (c == '(' || c == '[' || c == '{') {
                              left.push(c);
                       }
                       else { // 字符是‘)’ 或者 ‘]’ 或者 ‘}’
                              if (!left.empty() && leftOf(c) == left.top()) {
                                      left.pop();
                              }
                              else {
                                      // 和最近的左括号不匹配
                                      return false;
                              }
                       }
               }
               // 是否所有的左括号都被匹配了
               return left.empty();
        }
        char leftOf(char c) {
               if (c == ')') return '(';
               if (c == ']') return '[';
               return '{';
        }
};

