/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, i, j, 0, word)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, int l, string word) {
        if (l == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()
            || board[i][j] != word[l]) return false;
        char tmp = board[i][j];
        board[i][j] = '0';
        l = l + 1;
        if (dfs(board, i - 1, j, l, word)
            || dfs(board, i, j + 1, l, word)
            || dfs(board, i + 1, j, l, word)
            || dfs(board, i, j - 1, l, word))
        {
            return true;
        }
        board[i][j] = tmp;// 回溯
        return false;
    }
};

