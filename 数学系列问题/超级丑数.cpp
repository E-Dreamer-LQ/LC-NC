/*
超级丑数是指其所有质因数都是长度为 k 的质数列表 primes 中的正整数。

示例:

输入: n = 12, primes = [2,7,13,19]
输出: 32
解释: 给定长度为 4 的质数列表 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
*/ 

// 首先先联想丑数II的编程思想，
// dp保存按序排列的丑数，每个指针分别乘对应位置的素数找出下一个丑数。
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n);
        dp[0] = 1;
        vector<int> index(primes.size(), 0);
        for (int i = 1; i < n; i++) {
            int min = INT_MAX;
            for (int j = 0; j < index.size(); j++) {
                if (dp[index[j]] * primes[j] < min) {
                    min = dp[index[j]] * primes[j];
                }
                dp[i] = min;
            }
            for (int j = 0; j < index.size(); j++) {
                if (min == dp[index[j]] * primes[j]) {
                    index[j]++;
                }
            }
        }
        return dp[n - 1];
    }
};


