// 二维矩阵dp
#include<iostream>
#include <cstring>
using namespace std;

class Solution{ 
public: 
    int main() {
          int n;
          int m;
          while (~scanf_s("%d%d", &n, &m)) {
                 vector<int> v(n); // 物品体积
                 vector<int> w(n); // 物品价值
                 vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
                 for (int i = 0; i < n; i++) {
                         scanf_s("%d", &v[i]); // 我这里使用scanf会有错，可能是我的VS 2019的环境问题
                         scanf_s("%d", &w[i]);
                 }
                 for (int i = 1; i <= n; i++) {
                         for (int j = 1; j <= m; j++) {
                                // 当前背包容量装不下，只能选择不装入背包
                                if (j - v[i - 1] < 0) {
                                        dp[i][j] = dp[i - 1][j];
                                }
                                else {
                                        //装入或者不装，择优
                                        dp[i][j] = max(dp[i - 1][j - v[i - 1]] + w[i - 1],  dp[i - 1][j]);
                                }
                         }
                 }
                 cout << dp[n][m];
          }
          return 0;
      }
}


// 优化版本
const int N = 1010;
int f[N];
class Solution2{
public:
    int main()
    {
        int n,m;
        while(cin >> n >> m){
            int v,w;
            for (int i= 0 ; i < n;i++){
                cin >> v >> w;
                for(int j = m; j >= v;j--){
                    f[j] = max(f[j],f[j - v]+ w);
                }
            }
            cout << f[m] << endl;
        }
        return 0;
    }
}; 





