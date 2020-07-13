/*
给定一个包含了一些 0 和 1 的非空二维数组 grid 。

一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) { //dfs
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<int>> visited(n,vector<int> (m, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m ; j++){
                if (grid[i][j] == 1){
                    int num = dfs(grid,i, j, n, m);
                    res = max(res,num);
                }
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>> &grid , int i, int j , int n , int m){ // 这里不需要 visited矩阵代表已访问，改变grid本身可以表示访问过没
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1){
            return 0;
        }
        grid[i][j] = -1;
        return 1+
            dfs(grid,i+1, j ,n, m )+
            dfs(grid, i, j+1 , n,m)+
            dfs(grid, i,j-1, n ,m )+
            dfs(grid,i-1,j,n ,m);
        
    }
};

