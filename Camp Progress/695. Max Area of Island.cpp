// Question Link: https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size(), maxArea = 0, curArea;
        vector<int> dirs = { 0, 1, 0, -1, 0 };
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    curArea = dfs(grid, dirs, i, j, M, N);
                    maxArea = max(curArea, maxArea);
                }
            }   
        }
        
        return maxArea;
    }
    
    int dfs(vector<vector<int>> &grid, vector<int> &dirs, int i, int j, int &M, int &N) {
        int area = 1;
        grid[i][j] = 0;
        for (int d = 1; d < 5; d++) {
            int ni = i + dirs[d];
            int nj = j + dirs[d - 1];
            if (inside(ni, nj, M, N) && grid[ni][nj] == 1) {
                area += dfs(grid, dirs, ni, nj, M, N);
            }
        }
        
        return area;
    }
    
    bool inside(int i, int j, int &M, int &N) {
        if (i < 0 || i >= M || j < 0 || j >= N) {
            return false;
        }
        
        return true;
    }
};