// leetcode377-最佳观光组合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/best-sightseeing-pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 贪心法
class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& A) {
		int tmp = A[0] + 0;
		int res = INT_MIN;
		for (int i = 1; i < A.size(); i++) {
			res = max(res, tmp + A[i] - i);
			tmp = max(tmp, A[i] + i);
		}
		return res;
	}
};

void main() {
	Solution S;
	vector<int> A{8,1,5,2,6 };
	int res = S.maxScoreSightseeingPair(A);
	cout << res << endl;
}