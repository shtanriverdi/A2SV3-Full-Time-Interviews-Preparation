// Question Link: https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        int maxAreaIsland = 0;
        
        unordered_map<string, string> dsu;
        vector<vector<int>> ranks(M, vector<int>(N, 1));
        vector<int> dirs = { 0, 1, 0, -1, 0 };
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    maxAreaIsland = max(maxAreaIsland, ranks[i][j]);
                    for (int d = 1; d < 5; d++) {
                        int ni = dirs[d] + i;
                        int nj = dirs[d - 1] + j;
                        if (isInside(ni, nj, M, N) && grid[ni][nj] == 1) {
                            Union(i, j, ni, nj, dsu, ranks, maxAreaIsland);
                        }
                    }
                }
            }   
        }
        
        return maxAreaIsland;
    }
    
    void Union(int ai, int aj, int bi, int bj, unordered_map<string, string> &dsu, vector<vector<int>> &ranks, int &maxAreaIsland) {
        
        string a = getKey(ai, aj);
        string b = getKey(bi, bj);
        
        dsu[a] = (dsu[a] == "") ? a : dsu[a];
        dsu[b] = (dsu[b] == "") ? b : dsu[b];
        
        string parentA = find(a, dsu);
        string parentB = find(b, dsu);
        
        if (parentA == parentB) {
            return;
        }
        
        dsu[parentB] = parentA;
        
        vector<int> parA = getParentCoordinates(parentA);
        vector<int> parB = getParentCoordinates(parentB);
        
        ranks[parA[0]][parA[1]] += ranks[parB[0]][parB[1]];   
        
        maxAreaIsland = max({ maxAreaIsland, ranks[parA[0]][parA[1]], ranks[parB[0]][parB[1]] });
    }
    
    string find(string cur, unordered_map<string, string> &dsu) {
        if (dsu[cur] == cur) {
            return cur;
        }
        return dsu[cur] = find(dsu[cur], dsu);
    }
    
    bool isInside(int i, int j, int &M, int &N) {
        if (i < 0 || i >= M || j < 0 || j >= N) {
            return false;
        }
        return true;
    }
    
    vector<int> getParentCoordinates(string &parent) {
        int pos = 0;
        for (; pos < parent.size(); pos++) {
            if (parent[pos] == ',') {
                break;
            }
        }
        string i = parent.substr(0, pos), j = parent.substr(pos + 1);
        return { stoi(i), stoi(j) };
    }
    
    string getKey(int i, int j) {
        return to_string(i) + "," + to_string(j);
    }
};