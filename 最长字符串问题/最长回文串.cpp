// hashmap 
class Solution {
public:
        int longestPalindrome(string s) {
               if (s.size() == 0) return 0;
               map<char, int> hashmap;
               for (auto str : s) {
                       hashmap[str]++;
               }
               int count = 0;
               for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
                       if (it->second%2 == 0) {
                              count += it->second;
                       }
                       else {
                              count += it->second - 1;   // 如果有奇数个的，就变成偶数个的
                       }
               }
               if (count < s.size()) {      // 如果不是全部都是偶数个的， 则结果中只能有一个奇数个
                       count += 1;      
               }
               return count;
        }
};

