#include <iostream>
using namespace std; 

class Count_1_num {
public:
        int count(int n) {
               int res = 0;
               while (n) {
                       n = n & (n - 1);
                       res++;
               }
               return res;
        }
};
// 陷入死循环解
class Count_1_num_wrong {
public:
        int count(int n) {
               int res = 0;
               while (n) {
                       if (n & 1) res++;
                       n = n >> 1;
               }
               return res;
        }
};
//---------------正解--------------------------------
        //思想：用1（1自身左移运算，其实后来就不是1了）和n的每位进行位与，来判断1的个数
int Count_1_num_correct(int n) {
        int count = 0;
        int flag = 1;
        while (flag != 0) {
               if ((n & flag) != 0) {
                       count++;
               }
               flag = flag << 1;
        }
        return count;
}