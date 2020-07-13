/*给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。*/
// BFS

#include <iostream>
#include<vector>
#include <queue>
using namespace std;
typedef vector<vector<int>> vi;
struct P {
        int x, y, dis;
};
class Solution {
public:
    int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<P> que;
        int m = matrix.size(), n = matrix[0].size();
        vi vis(m, vector<int>(n, 0));
        vi res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0)
                    que.push({ i, j, 0 }), vis[i][j] = 1; // 直接进队列，此处就是0
        while (!que.empty())
        {
            P temp = que.front();
            que.pop();
            int x = temp.x, y = temp.y, d = temp.dis;
            vis[x][y] = 1;
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) continue;
                que.push({ nx, ny, d + 1 });
                res[nx][ny] = d + 1;  
                vis[nx][ny] = 1;  // 表示已访问
            }
        }
        return res;
    }
};