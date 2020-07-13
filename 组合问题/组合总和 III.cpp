// leetcode216-组合总和 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/combination-sum-iii

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	vector<vector<int>> res;
	vector<int> temp;
	void dfs(int k, int n,int start) {
		if (n < 0) return ;
		if (n == 0 && temp.size()==k) {
			res.push_back(temp);
			return ;
		}
		for (int i = start; i <= 9; i++) {
			if (n < i) return;	//剪枝
			temp.push_back(i);
			dfs(k, n-i, i+1);
			temp.pop_back();
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		dfs(k, n, 1);
		return res;
		
	}
};

