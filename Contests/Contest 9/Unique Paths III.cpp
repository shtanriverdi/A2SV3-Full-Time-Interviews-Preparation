// Question Link: https://leetcode.com/problems/unique-paths-iii/

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        
        vector<int> start, end;
        int obstaclesCount = 0;
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    start = { i, j };
                }
                else if (grid[i][j] == 2) {
                    end = { i, j };
                }
                else if (grid[i][j] == -1) {
                    obstaclesCount++;
                }
            }
        }
        
        int totalUniqPaths = (M * N) - obstaclesCount;
        int uniqs = 0;
        
        vector<int> dirs = { 0, 1, 0, -1, 0 };
        vector<vector<int>> path;
        
        dfs(uniqs, start[0], start[1], M, N, grid, dirs, end, path, totalUniqPaths);
        
        return uniqs;
    }
    
    void dfs(int &uniqs, int i, int j, int &M, int &N, vector<vector<int>>& grid, vector<int> &dirs, vector<int> &end, vector<vector<int>> &path, int &totalUniqPaths) {
        int prevInfo = grid[i][j];
        grid[i][j] = 9;
        
        path.push_back({ i, j });
        
        if (i == end[0] && j == end[1] && path.size() == totalUniqPaths) {
            uniqs++;
            // Backtracking
            grid[i][j] = prevInfo;
            path.pop_back();
            return;
        }
        
        for (int d = 1; d < 5; d++) {
            int ni = i + dirs[d];
            int nj = j + dirs[d - 1];
            if (inside(ni, nj, M, N) && (grid[ni][nj] != 9 && grid[ni][nj] != -1)) {
                dfs(uniqs, ni, nj, M, N, grid, dirs, end, path, totalUniqPaths);
            }
        }
        
        // Backtracking
        grid[i][j] = prevInfo;
        path.pop_back();
    }
    
    bool inside(int i, int j, int &M, int &N) {
        if (i < 0 || j < 0 || i >= M || j >= N) {
            return false;
        }
        return true;
    }
};