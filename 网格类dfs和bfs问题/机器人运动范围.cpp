/*
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），
因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/


class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<int>> flag(rows, vector<int>(cols, 0));
        return helper(0, 0, rows, cols, flag, threshold);
    }


    int helper(int i, int j, int rows, int cols, vector<vector<int>> &flag, int threshold) { // 必须要& 
        if (i < 0 || i >= rows || j < 0 || j >= cols || count(i) + count(j) > threshold || flag[i][j] == 1) { // 递归终止条件
            return 0;
        }
        flag[i][j] = 1; // 标记已经访问
        return helper(i - 1, j, rows, cols, flag, threshold)
            + helper(i + 1, j, rows, cols, flag, threshold)
            + helper(i, j - 1, rows, cols, flag, threshold)
            + helper(i, j + 1, rows, cols, flag, threshold)
            + 1;
    }
    int count(int n) { // 计算整数 n 位数之和
        int res = 0;
        while (n != 0) {
            res += n % 10;
            n = n / 10;
        }
        return res;
    }
};

