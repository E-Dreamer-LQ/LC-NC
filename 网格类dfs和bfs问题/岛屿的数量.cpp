/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。
*/

// dfs
class Solution {
public:
        int numIslands(vector<vector<char>>& grid) {
               int row = grid.size();
               if (!row) return 0;
               int col = grid[0].size();
               int res = 0;
               for (int i = 0; i < row; i++) {
                       for (int j = 0; j < col; j++) {
                              if (grid[i][j] == '1') {
                                      res++;
                                      dfs(grid, i, j);
                              }
                       }
               }
               return res;
        }
        void dfs(vector<vector<char>>& grid, int i, int j) {  // 将1连成块的算成一个岛屿
               int nr = grid.size();
               int nc = grid[0].size();
               grid[i][j] = '0';
               if (i - 1 >= 0 && grid[i-1][j] == '1') {
                       dfs(grid, i - 1, j);
               }
               if (i + 1 < nr && grid[i + 1][j] == '1') {
                       dfs(grid, i + 1, j);
               }
               if (j - 1 >= 0 && grid[i][j-1] == '1') {
                       dfs(grid, i, j - 1);
               }
               if (j + 1 < nc && grid[i][j+1] == '1') {
                       dfs(grid, i, j + 1);
               }
        }
};
// bfs
class Solution {
public:
        int numIslands(vector<vector<char>>& grid) {
               int row = grid.size();
               if (!row) return 0;
               int col = grid[0].size();
               int res = 0;
               for (int i = 0; i < row; i++) {
                       for (int j = 0; j < col; j++) {
                              if (grid[i][j] == '1') {
                                      ++res;
                                      grid[i][j] = '0';
                                      queue<pair<int, int>> que;
                                      que.push({ i,j });
                                      while (!que.empty()) {
                                             auto cur = que.front();
                                             que.pop();
                                             int cur_row = cur.first;
                                             int cur_col = cur.second;
                                             if (cur_row - 1 >= 0 && grid[cur_row -  1][cur_col] == '1') {
                                                     que.push({ cur_row - 1,cur_col });
                                                     grid[cur_row - 1][cur_col] = '0'; // 出队列前标记
                                             }
                                             if (cur_row + 1 < row && grid[cur_row +  1][cur_col] == '1') {
                                                     que.push({ cur_row + 1,cur_col });
                                                     grid[cur_row + 1][cur_col] = '0';
                                             }
                                             if (cur_col - 1 >= 0 &&  grid[cur_row][cur_col-1] == '1') {
                                                     que.push({ cur_row,cur_col -1 });
                                                     grid[cur_row][cur_col - 1]  = '0';
                                             }
                                             if (cur_col + 1 < col && grid[cur_row  ][cur_col+1] == '1') {
                                                     que.push({ cur_row,cur_col+1 });
                                                     grid[cur_row][cur_col+1] = '0';
                                             }
                                      }
                              }
                       }
               }
               return res;
        }
};