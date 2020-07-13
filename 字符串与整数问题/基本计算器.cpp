/*
对于非数字字符来说，有三种情况：
'+': 将这个字符后面的数压入堆栈nums中
'-': 将这个字符后面的数取反后压入堆栈nums中
'*' 或 '/': nums.top()为这个符号前面的数，而num为这个符号后面的数，
根据符号计算这两个数的值后，再压入堆栈
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
        int calculate(string s) {
               int res = 0, num = 0;
               char sign ='+';
               stack<int> nums;
               for (int i = 0; i < s.size(); i++) {
                       if (s[i] >= '0') {
                              num = num * 10 - '0' + s[i];
                       }
                       if ((s[i] < '0' && s[i] != ' ') || i == s.size() - 1) {
                              if (sign == '+') {
                                      nums.push(num); // 初始时就是"+"
                              }
                              else if (sign == '-') {
                                      nums.push(-num);
                              }
                              else if (sign == '*' || sign == '/') {
                                      int temp = sign == '*' ? nums.top() * num :  nums.top() / num;
                                      nums.pop();
                                      nums.push(temp);
                              }
                              sign = s[i];
                              num = 0;
                       }
               }
               while (!nums.empty()) {
                       res += nums.top();
                       nums.pop();
               }
               return res;
        }
};

