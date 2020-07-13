// leetcode377-组合求和 IV.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/combination-sum-iv/

#include <iostream>
#include <vector> 
using namespace std;


// 方法一： 回溯法, 超时
class Solution {
public:
	vector<vector<int>> res;
	vector<int> temp;
	void dfs(vector<int>& nums, int target) {
		// 遍历条件
		if (target == 0) {
			res.push_back(temp);
			return;
		}
		if (target < 0) {
			return;
		}
		// 开始搜索
		for (int i = 0; i < nums.size(); i++) {
			if (target < nums[i]) continue ; // 剪枝
			temp.push_back(nums[i]);
			dfs(nums, target-nums[i]);
		}
	}
	int combinationSum4(vector<int>& nums, int target) {
		dfs(nums, target);
		return res.size();
	}
};


// 动态规划

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        vector<unsigned long long> dp(target+1, 0);              
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for(auto j: nums){
                if (i >= j){
                    dp[i] += dp[i-j];
                }
            }
        }
        return dp[target];    
    }
};




void main() {
	vector<int> nums{ 1,2,3 };
	int target = 4;
	Solution S;
	Solution S2; 
	int res = S.combinationSum4(nums, target);
	int res2 = S2 
	cout << res << endl;
}







