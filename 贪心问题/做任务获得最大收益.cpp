/*
题目描述： 
n 个任务的起始时间，结束时间， 和 任务获得的金币。
求通过做任务获得的最大金币数
*/ 
#include <bits/stdc++.h>
using namespace std;

struct mission {
       int s;
       int e;
       int w;
};
int main() {
       int n;
       cin >> n;
       vector<mission> M(n);
       for (int i = 0; i < n; i++) {
              cin >> M[i].s >> M[i].e >> M[i].w;
       }
       auto cmp = [](const mission& a, const mission& b) {
              return a.e < b.e;
       };
       sort(M.begin(), M.end(),cmp);
       vector<int> front(n, -1); // 与第i个任务相容的前一个任务编号
       for (int i = n - 1; i >= 0; i--) {
              for (int j = i - 1; j >= -1; j--) {
                     if (M[j].e < M[i].s) { //  #这里有个坑，前一个任务的e必须小于后一个任务的s
                           front[i] = j;
                           break;
                     }
              }
       }
       vector<int> dp(n); // 以第 i 个任务结尾的最大收益
       dp[0] = M[0].w;
       for (long long i = 1; i < n; i++) {
              if (front[i] >= 0) { // 有相容的任务
                     dp[i] = max(dp[i - 1], dp[front[i]] + M[i].w);   // 当前相容的任务
              }
              else {   // 当前任务无相容的任务
                     dp[i] = max(dp[i - 1], M[i].w);
              }
       }
       return dp[n-1];
}