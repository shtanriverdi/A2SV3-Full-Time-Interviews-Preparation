// Question Link: https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        
        queue<tuple<int, int, int>> todo;
        
        unordered_map<string, bool> freshMap;
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 2) {
                    todo.push({ i, j, 0 });
                }
                else if (grid[i][j] == 1) {
                    string key = to_string(i) + to_string(j);
                    freshMap[key];
                }
            }      
        }
        
        vector<int> dirs = { 0, 1, 0, -1, 0 };
        
        int minMinutes;
        while (!todo.empty()) {
            auto [ ci, cj, cMin ] = todo.front();
            todo.pop();
            minMinutes = cMin;
            for (int i = 1; i < 5; i++) {
                int ni = ci + dirs[i];
                int nj = cj + dirs[i - 1];
                if (inside(ni, nj, M, N) && grid[ni][nj] == 1) {
                    todo.push({ ni, nj, cMin + 1 });
                    grid[ni][nj] = 2;
                    string key = to_string(ni) + to_string(nj);
                    freshMap.erase( key );
                }
            }
        }
        
        return freshMap.size() == 0 ? minMinutes : -1;
    }
    
    bool inside(int i, int j, int &M, int &N) {
        if (i < 0 || i >= M || j < 0 || j >= N) {
            return false;
        } 
        return true;
    }
};