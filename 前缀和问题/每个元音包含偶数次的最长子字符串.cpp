/*
给你一个字符串s，请你返回满足以下条件的最长子字符串的长度：每个元音字母，
即'a，'e'，i'，"o'，'u'，在子字符串中都恰好出现了偶数次。
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
        int findTheLongestSubstring(string s) {
               int ans = 0, status = 0, n = s.size();
               vector<int> pos(32, -1);
               pos[0] = 0; // 前 0 个字符可以使得状态码变为 0，一定要记住：pos[status] = i + 1 的意思是前 i + 1 个字符运算后的状态码为 status！
               for (int i = 0; i < n; i++) {
                       if (s[i] == 'a') {
                              status ^= 1 << 0; // status ^= 00001, 1 左移1位
                       }
                       else if (s[i] == 'e') {
                              status ^= 1 << 1; // status ^= 00010   左移2位
                       }
                       else if (s[i] == 'i') {
                              status ^= 1 << 2;  // status ^= 00100
                       }
                       else if (s[i] == 'o') {
                              status ^= 1 << 3;  // status ^= 01000
                       }
                       else if (s[i] == 'u') {
                              status ^= 1 << 4;  // status ^= 10000
                       }
                       if (pos[status] != -1) {// 状态码存在，这里也可以用hashmap 代替
                              ans = max(ans, i + 1 - pos[status]);
                       }
                       else {
                              pos[status] = i + 1;
                       }
               }
               return ans;
        }
};

