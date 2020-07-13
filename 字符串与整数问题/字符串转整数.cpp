/*
字符串转化为整数，一律先变成负数来转，主要防止越界
*/

// 牛客上面的版本
class Solution {
public:
    int StrToInt(string str) {
        if (str[0] == '+') str = str.erase(0,1);
        bool IsCanConvert = Check_Convert(str);
        if (!IsCanConvert) return 0;
        bool position = str[0] == '-' ? false : true; // 符号位，整数为true 
        int minq = INT_MIN / 10;
        int minr = INT_MIN % 10;
        int res = 0;
        int cur = 0;
        for (int i = position ? 0 : 1; i < str.size(); i++) {
            cur = '0' - str[i]; // 使用负数
            if (res < minq || (res == minq && cur < minr)) {
                return 0;
            }
            res = res * 10 + cur;
        }
        if (position && res == INT_MIN) {
            return 0;
        }
        return position ? -res : res;
    }
    bool Check_Convert(string str) {
        if (str[0] != '-' && ( str[0] > '9' || str[0] < '0')) return false;
        if (str[0] == '-' && (str.size() == 1 || str[1] == '0')) return false;
        if (str[0] == '0' && str.size() > 0) return false;
        for (int i = 1; i < str.size(); i++) {   // 从1 开始算起
            if (str[i] < '0' || str[i] > '9') {
                return false;
            }
        }
        return true;
    }
};



// Leetcode 题目要求, 带空格输入
/*
输入: "42"
输出: 42
示例 2:

输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
示例 3:

输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
示例 4:

输入: "words and 987"    （正常情况不能去转换）
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
示例 5:

输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
     因此返回 INT_MIN (−231) 。
*/

class Solution {
public:
        int myAtoi(string str) {
               int i = 0;//位置
               long long res = 0;//输出结果
               int bol = 1;//符号
               while (i < str.size() && str[i] == ' ')++i;//找到第一个非空格的字符
               if (i == str.size())return 0;
               if (str[i] == '-') {
                       bol = -1;
                       ++i;   //运算符正负号
               }
               else if (str[i] == '+') {
                       bol = 1;
                       ++i;
               }
               while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
                       res = res * 10 + str[i++] - '0';
                       if (res >= 2147483648) {
                              if (bol == 1)return INT_MAX;
                              else return INT_MIN;
                       }
               }
               return res * bol;
               }
};
