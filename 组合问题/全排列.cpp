// leetcode46-全排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 原题链接：https://leetcode-cn.com/problems/permutations/
/* 回溯法
递归结束条件
变量状态的改变与恢复（tmp数组）
递归参数中的变量和常量，在循环中变量如何改变！！！
*/
/*
如果第一个整数有索引 n，意味着当前排列已完成。
遍历索引 first 到索引 n - 1 的所有整数。Iterate over the integers from index first to index n - 1.
在排列中放置第 i 个整数，
即 swap(nums[first], nums[i]).
继续生成从第 i 个整数开始的所有排列: backtrack(first + 1).
现在回溯，即通过 swap(nums[first], nums[i]) 还原.
*/


#include <iostream>
#include <vector>
using namespace std; 


class Solution {
public:
	void dfs(int n, vector <vector<int>>& res, vector<int>& nums, int first) {
		if (first == n) {
			res.push_back(nums);
			return;
		}
		for (int i = first; i < n; i++) {
			swap(nums[i], nums[first]);
			dfs(n, res, nums, first+1);
			swap(nums[i], nums[first]);
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		dfs(nums.size(), res, nums, 0);
		return res;
	}
};


void main() {
	Solution S;
	vector<int> nums{ 1, 2, 3 };
	vector<vector<int>> res = S.permute(nums);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	// 使用迭代器打印二维数组
	cout << "Use iterator to print:" <<endl;
	vector<int>::iterator it;
	vector<vector<int>>::iterator iter;
	vector<int> vec_tmp;

	for (iter = res.begin(); iter != res.end(); iter++)
	{
		vec_tmp = *iter;
		for (it = vec_tmp.begin(); it != vec_tmp.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
}
