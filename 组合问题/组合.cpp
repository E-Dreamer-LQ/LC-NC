// leetcode77-组合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/combinations

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> combine(int n, int k) {
        dfs(1,n,k);
        return res;
        
    }
    void dfs(int start, int n, int k){
        if (temp.size() >= k){
            if (temp.size() == k){
                res.push_back(temp);
            }
            return ;  
        }
        for(int i = start; i <= n;i++){
            temp.push_back(i);
            dfs(i+1,n,k);
            temp.pop_back();
        }
    }
};
void main() {
	Solution S;
	int n = 4;
	int k = 2;
	vector<vector<int>> res = S.combine(n, k);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}