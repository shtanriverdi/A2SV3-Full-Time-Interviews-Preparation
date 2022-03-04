// Question Link: https://leetcode.com/problems/minesweeper

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int M = board.size();
        int N = board[0].size();
        vector<vector<int>> dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1,1} };
        
        char cur = board[click[0]][click[1]];
        if (cur == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        if (cur == 'E') {
            expand(click[0], click[1], board, M, N, dirs);
        }
        
        return board;
    }
    
    void expand(int ci, int cj, vector<vector<char>> &B, int &M, int &N, vector<vector<int>> dirs) {
        int adjMineCount = getAdjacentMines(ci, cj, B, M, N, dirs);
        if (adjMineCount == 0) {
            B[ci][cj] = 'B';
            for (vector<int> &dir : dirs) {
                int ni = ci + dir[0];
                int nj = cj + dir[1];
                if (inside(ni, nj, M, N) && B[ni][nj] == 'E') {
                    expand(ni, nj, B, M, N, dirs);
                }
            }
        }
        else {
            B[ci][cj] = '0' + adjMineCount;
        }
    }
    
    int getAdjacentMines(int ci, int cj, vector<vector<char>> &B, int &M, int &N, vector<vector<int>> dirs) {
        int mineCount = 0;
        for (vector<int> &dir : dirs) {
            int ni = ci + dir[0];
            int nj = cj + dir[1];
            if (inside(ni, nj, M, N) && B[ni][nj] == 'M') {
                mineCount++;
            }
        }
        
        return mineCount;
    }
    
    bool inside(int i, int j, int &M, int &N) {
        if (i < 0 || i >= M || j < 0 || j >= N) {
            return false;
        }
        
        return true;
    }
};