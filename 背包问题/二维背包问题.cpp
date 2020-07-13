
// 约束： 背包的容量和背包的重量
#include <iostream>
#include<algorithm>
#include <cstring>

using namespace std;
const int N = 110;
int n, v, m;
int f[N][N];

int main() {
    cin >> n >> v >> m;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = v; j >= a; j--) {
            for (int k = m; k >= b; k--) {
                f[j][k] = max(f[j][k], f[j - a][k - b] + c);
            }
        }
    }
    cout << f[v][m] << endl;
    return 0;
}