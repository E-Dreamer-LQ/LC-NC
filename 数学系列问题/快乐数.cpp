/*
编写一个算法来判断一个数n是不是快乐数。
「快乐数」定义为：对于个正整数，每一次将该数替换为它每个位置上的数字的平
方和，然后重复这个过程直到这个数变为1，也可能是无限循环但始终变不到1.如
果可以变为1，那么这个数就是快乐数。
*/

// 使用一个hashmap 统计是否会进入循环
class Solution {
public:
        map<int, int> hashmap;
        int count(int n) {
               int res = 0;
               while (n) {
                       res += pow((n % 10), 2);
                       n = n / 10;
               }
               return res ;
        }
        bool isHappy(int n) {
               while (n != 1) {
                       if (hashmap.count(n) > 0) {
                              return false;
                       }
                       hashmap[n]++;
                       n = count(n);
               }
               return true;
        }
};
// 快慢指针
class Solution2 {
public:
        int count(int n) {
               int res = 0;
               while (n) {
                       res += pow((n % 10), 2);
                       n = n / 10;
               }
               return res;
        }
        bool isHappy(int n) {
               int slow = n, fast = n;
               do {
                       slow = count(slow);
                       fast = count(fast);
                       fast = count(fast); // fast = count(count(fast))
               } while (slow != fast);
               return slow == 1;
        }
};

