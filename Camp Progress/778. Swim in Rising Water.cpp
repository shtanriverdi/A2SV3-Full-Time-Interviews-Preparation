// Question Link: https://leetcode.com/problems/swim-in-rising-water/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        
        // { maxElevation, {i,j} }
        priority_queue<pair<int, vector<int>>> todo;
        todo.push({ -1 * grid[0][0], {0, 0} });
        
        vector<int> dirs = { 0, 1, 0, -1, 0 };
        grid[0][0] = -1;

        while (!todo.empty()) {
            auto[ maxElevation, cur ] = todo.top();
            todo.pop();
            for (int d = 1; d < 5; d++) {
                int ni = cur[0] + dirs[d];
                int nj = cur[1] + dirs[d - 1];
                if (inside(ni, nj, N) && grid[ni][nj] != -1) {
                    if (ni == N - 1 && nj == N - 1) {
                        return max(grid[ni][nj], maxElevation * -1);
                    }
                    todo.push({ -1 * max(grid[ni][nj], maxElevation * -1), { ni, nj } });
                    grid[ni][nj] = -1;
                }
            }            
        }
        
        return 0;
    }
    
    bool inside(int i, int j, int &N) {
        if (i < 0 || i >= N || j < 0 || j >= N) {
            return false;
        }
        
        return true;
    }
};