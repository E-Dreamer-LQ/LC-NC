#include<iostream> 
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
        int N, n[105], c[105], v[105], dp[105][105], p = 0, V;
        memset(dp, 0, sizeof(dp));
        cin >> N >> V;
        for (int i = 1; i <= N; i++)
        {
               cin >> v[i] >> c[i] >> n[i];
        }
        for (int i = 1; i <= N; i++)
        {
               for (int j = V; j >= 0; j--)
               {
                       for (int k = 0; k <= n[i]; k++) // 该种物品的个数循环
                       {
                              //因此当k = 0时，实际上就是dp[i - 1][j]。
                              //状态转移方程为：dp[i][j] = max(dp[i - 1][j], dp[i - 1][j -  v] + w, dp[i - 1][j - 2v] + 2w, …) : 这里有多重选法
                              if (j >= k * v[i])
                              {
                                      dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k  * c[i]);
                              }
                       }
               }
        }
        p = dp[N][V];
        cout << p;
}

// 一维优化版本
int n, m;
const int N = 110;
int f[N];
int main0() {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
               int v, w, s;
               cin >> v >> w >> s;
               for (int j = m; j >= 0; j--) {
                       for (int k = 1; k <= s && k * v <= j; k++) {
                              f[j] = max(f[j], f[j - k * v] + k * w);
                       }
               }
        }
        cout << f[m] << endl;
        return 0;
}

