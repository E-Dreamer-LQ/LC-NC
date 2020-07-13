// leetcode40-组合总和 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/combination-sum-ii

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

// 重点如何去除重复
class Solution {
public:
	vector<vector<int>> res;
	vector<int> temp;
	void dfs(vector<int>& candidates, int target, int start) {
		if (target == 0) { 
			res.push_back(temp);   // 终止条件
			return;      
		}
		for (int i = start; i < candidates.size(); i++) {
			if (target - candidates[i] >= 0) {
				if (i != start && candidates[i] == candidates[i - 1]) // 去掉重复
					continue;
				temp.push_back(candidates[i]);
				dfs(candidates, target-candidates[i], i+1);
				temp.pop_back();
			}
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		// 对candidates 排序
		sort(candidates.begin(), candidates.end());
		dfs(candidates, target, 0);
		return res;
		

	}
};

// 利用set来去重
class Solution2 {
public:
	vector<int> tmp;
	vector<vector<int>> res;
	set<vector<int>> s;    // 去除重复的组合
	void dfs(vector<int>& candidates, int target, int start) {
		if (target <= 0) {
			if (target == 0) {
				s.insert(tmp);
			}
			return;
		}
		for (int i = start; i < candidates.size(); i++) {
			tmp.push_back(candidates[i]);
			dfs(candidates, target - candidates[i], i + 1);
			tmp.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		dfs(candidates, target, 0);
		for (auto i : s) {
			res.push_back(i);
		}
		return res;
	}
};



void main() {
	Solution S;
	vector<int> candidates{ 2,5,2,1,2 };
	int target = 5;
	vector<vector<int>> res = S.combinationSum2(candidates, target);
	for (int i = 0; i < res.size(); i++) {

		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
