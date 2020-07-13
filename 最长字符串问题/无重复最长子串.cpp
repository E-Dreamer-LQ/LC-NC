// 无重复最长子串

#include<ioiostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std 

//方法一： 使用滑动窗口
int LongestNoRepeatSubstr(string s) {
    unordered_map<char, int> window;
    int left = 0, right = 0;
    int res = 0; // 记录结果
    while (right < s.size()) {
        char c = s[right];
        right++;
        // 进行窗口内数据的一系列更新
        window[c]++;
        // 判断左侧窗口是否要收缩
        while (window[c] > 1) {
            char d = s[left];
            left++;
            // 进行窗口内数据的一系列更新
            window[d]--;
        }
        // 在这里更新答案
        res = max(res, right - left);
    }
    return res;
}


// 方法二： 使用hashmap边遍历边存储
int LongestNoRepeatSubstr(string str) {
       if (str.size() == 0) return 0;
       unordered_map<char, int> hashmap; // hashmap 记录的 字符出现的 index
       int max_length = 0;
       int left =g 0;
       for (int i = 0; i < str.size(); i++) {
               if (hashmap.find(str[i]) != hashmap.end()) {
                      left = max(left, hashmap[str[i]] + 1); //出现重复后 更新左边界
               }
               max_length = max(max_length, i - left + 1);
               hashmap[str[i]] = i;
       }
       return max_length;
}