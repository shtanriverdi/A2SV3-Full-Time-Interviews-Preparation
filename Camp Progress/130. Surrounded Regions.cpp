// Question Link: https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int M = board.size();
        int N = board[0].size();
        
        bool seen[200][200] = { false };
        
        vector<int> dirs = { 0, 1, 0, -1, 0 };
        
        for (int j = 0; j < N; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j, dirs, seen, M, N);
            }
            if (board[M - 1][j] == 'O') {
                dfs(board, M - 1, j, dirs, seen, M, N);
            }
        }
        
        for (int i = 0; i < M; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0, dirs, seen, M, N);
            }
            if (board[i][N - 1] == 'O') {
                dfs(board, i, N - 1, dirs, seen, M, N);
            }
        }
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'O' && seen[i][j] == false) {
                    board[i][j] = 'X';
                }
            }   
        } 
    }
    
    void dfs(vector<vector<char>> &board, int i, int j, vector<int> &dirs, bool seen[200][200], int &M, int &N) {
        seen[i][j] = true;
        for (int d = 1; d < 5; d++) {
            int ni = i + dirs[d];
            int nj = j + dirs[d - 1];
            if (inside(ni, nj, M, N) && seen[ni][nj] == false && board[ni][nj] == 'O') {
                dfs(board, ni, nj, dirs, seen, M, N);
            }
        }
    }
    
    bool inside(int i, int j, int &M, int &N) {
        if (i < 0 || i>= M || j < 0 || j >= N) {
            return false;
        }
        return true;
    } 
};