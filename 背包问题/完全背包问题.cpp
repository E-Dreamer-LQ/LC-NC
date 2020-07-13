// 二维矩阵动态规划， 转化为01 背包
#include<iostream>
using namespace std;
const int N = 1010;
int f[N][N];
int v[N], w[N];
int main()
{
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
               cin >> v[i] >> w[i];
        }
        for (int i = 1; i <= n; i++)
               for (int j = 0; j <= m; j++)
               {
                       for (int k = 0; k * v[i] <= j; k++)
                              f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
               }
        cout << f[n][m] << endl;
}
// 优化版本
int main2()
{
        const int N = 1010;
        vector<int> dp(N);
        vector<int> v(N);
        vector<int> w(N);
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
               cin >> v[i] >> w[i];
        }
        for (int i = 1; i <= n; i++)
               for (int j = v[i]; j <= m; j++)
               {
                       dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
               }
        cout << dp[m] << endl;
}

