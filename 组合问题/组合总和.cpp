// leetcode39-组合总和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/combination-sum/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	vector<int> temp;
	void process(int start, vector<int>& candidates, int target) {
		// 终止条件
		if (target < 0) return;
		if (target == 0) {
			res.push_back(temp);
		}
		else {
			for (int i = start; i < candidates.size(); i++) {
				// 优化,剪枝
				if (target < candidates[i])
					break;
				temp.push_back(candidates[i]);
				//因为每个数字都可以使用无数次，所以递归还可以从当前元素开始
				process(i+1,candidates,target - candidates[i]);
				temp.pop_back();
			}
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.size() < 0) return res;
		process(0,candidates, target);
		return res;
	}
};


void main() {
	Solution S;
	vector<int> candidates{2,2,3,7};
	int target = 7;
	vector<vector<int>> res = S.combinationSum(candidates, target);
	for (int i = 0; i < res.size(); i++) {
	
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}