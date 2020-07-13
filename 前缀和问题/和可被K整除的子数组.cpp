#include <iostream>
#include<vector>
#include <unordered_map>
using namespace std;
// 方法一:前缀和
/*
let A = [4,5,0,-2,-3,1], K = 5
let map = {0: 1}
let preSum = 0, count = 0
循环A
i = 0,  preSum = (0 + 4) % 5 = 4, map中不存在4 => map[4] = 1
i = 1,  preSum = (4 + 5) % 5 = 4, map中存在4 => count += map[4] => count = 1,  map[4] =  map[4] + 1 = 2
i = 2,  preSum = (4 + 0) % 5 = 4, map中存在4 => count += map[4] => count = 3,  map[4] = 3
i = 3,  preSum = (4 - 2) % 5 = 2, map中不存在2 => map[2] = 1
i = 4,  preSum = (2 - 3) % 5 = -1 小于0 => preSum = -1 + 5 = 4, map中存在4 => count +=  map[4] => count = 6,  map[4] = 4
i = 5,  preSum = (4 + 1) % 5 = 0, map中存在0 => count += map[0] => count = 7, map[0] = 2
*/
class Solution {
public:
        int subarraysDivByK(vector<int>& A, int K) {
               if (A.size() == 0) return 0;
               unordered_map<int, int> hashmap;
               hashmap[0] = 1;
               int preSum = 0;
               int count = 0;
               for (int i = 0; i < A.size(); i++) {
                       preSum = (preSum + A[i]) % K;
                       if (preSum < 0) preSum += K;
                       count += hashmap[preSum];// 索引是mod , 值是出现次数
                       hashmap[preSum]++;
               }
               return count;
        }
};

