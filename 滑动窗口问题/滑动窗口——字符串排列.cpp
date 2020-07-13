/*
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
*/

#include<iostream>
#include <cstring>
#include <queue>
#include <unordered_map>
using namespace std ; 
// 判断 s 中是否存在 t 的排列
bool checkInclusion(string t, string s) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    int left = 0, right = 0;
    int valid = 0;
    while (right < s.size()) {
       char c = s[right];
       right++;
       // 进行窗口内数据的一系列更新
       if (need.count(c)) {
           window[c]++;
           if (window[c] == need[c])
              valid++;
       }
       // 判断左侧窗口是否要收缩:窗口大小 >= t.size()
       while (right - left >= t.size()) {
           // 在这里判断是否找到了合法的子串
           if (valid == need.size())
              return true;
           char d = s[left];
           left++;
           // 进行窗口内数据的一系列更新
           if (need.count(d)) {
              if (window[d] == need[d])
                      valid--;
              window[d]--;
           }
       }
    }
    // 未找到符合条件的子串
    return false;
}

