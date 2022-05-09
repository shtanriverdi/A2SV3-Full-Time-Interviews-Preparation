// Question Link: https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> rank(n, 1);
        vector<int> dsu(n);
        for (int i = 0; i < n; i++) {
            dsu[i] = i;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    Union(i, j, dsu, rank);
                    isConnected[i][j] = 0;
                    isConnected[j][i] = 0;
                }
            }   
        }
        
        unordered_set<int> provinces;
        for (int i = 0; i < n; i++) {
            provinces.insert(find(dsu[i], dsu));
        }
        
        return provinces.size();
    }
    
    int find(int cur, vector<int> &dsu) {
        if (dsu[cur] == cur) {
            return cur;
        }
        dsu[cur] = find(dsu[cur], dsu);
        return dsu[cur];
    }
    
    void Union(int a, int b, vector<int> &dsu, vector<int> &rank) {
        int A = find(a, dsu);
        int B = find(b, dsu);
        
        if (A == B) {
            return;
        }
        
        if (rank[B] > rank[A]) {
            swap(B, A);
        }
        dsu[B] = A;
        
        rank[A] += rank[B];
    }
};