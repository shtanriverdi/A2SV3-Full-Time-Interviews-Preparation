// Question Link: https://leetcode.com/problems/number-of-enclaves

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        vector<int> dirs = { 0, 1, 0, -1, 0 };
        
        for (int i = 0; i < M; i++) {
            if (grid[i][0] == 1) {
                dfs(grid, i, 0, M, N, dirs);
            }
            if (grid[i][N - 1] == 1) {
                dfs(grid, i, N - 1, M, N, dirs);
            }
        }
        
        for (int j = 0; j < N; j++) {
            if (grid[0][j] == 1) {
                dfs(grid, 0, j, M, N, dirs);
            }
            if (grid[M - 1][j] == 1) {
                dfs(grid, M - 1, j, M, N, dirs);
            }
        }
        
        int numOfEnclaves = 0;
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                numOfEnclaves += grid[i][j] == 1;
            }   
        }
        
        return numOfEnclaves;
    }
    
    void dfs(vector<vector<int>> &grid, int i, int j, int &M, int &N, vector<int> &dirs) {
        grid[i][j] = 0;
        for (int d = 1; d < 5; d++) {
            int ni = i + dirs[d];
            int nj = j + dirs[d - 1];
            if (inside(ni, nj, M, N) && grid[ni][nj] == 1) {
                dfs(grid, ni, nj, M, N, dirs);
            }
        }
    }
    
    bool inside(int i, int j, int &M, int &N) {
        if (i < 0 || i >= M || j < 0 || j >= N) {
            return false;
        }
        
        return true;
    }
};