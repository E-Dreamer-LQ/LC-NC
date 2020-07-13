#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 2010;
int f[N];
struct Goods
{
    int v;
    int w;
};

int main() {
    int n, m;
    vector<Goods> goods;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
       int v, w, s;
       cin >> v >> w >> s;
       for (int k = 1; k <= s; k *= 2) {
               s -= k;  
               goods.push_back({ v * k,w * k });
       }
       if (s > 0) goods.push_back({ v * s,w * s }); // 如果 s还有剩余的
    }
    for (auto good : goods) {
       for (int j = m; j >= good.v; j--) {
               f[j] = max(f[j], f[j - good.v] + good.w);  //转化为01背包
       }
    }
    cout << f[m] << endl;
    return 0;
}




