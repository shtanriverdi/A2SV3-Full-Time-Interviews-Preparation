// Question Link: https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    int findCircleNum(vector<vector<int>> &adjMatrix) {
        int N = adjMatrix.size(), count = 0;
        for (int i = 0; i < N; i++) {
            if (adjMatrix[i][i] == 1) {
                dfs(adjMatrix, i, N);
                count++;
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<int>> &adjMatrix, int cur, int &N) {
        adjMatrix[cur][cur] = 0;
        for (int i = 0; i < N; i++) {
            if (adjMatrix[cur][i] == 1) {
                adjMatrix[cur][i] = 0;
                adjMatrix[i][cur] = 0;
                dfs(adjMatrix, i, N);
            }
        }
    }
};