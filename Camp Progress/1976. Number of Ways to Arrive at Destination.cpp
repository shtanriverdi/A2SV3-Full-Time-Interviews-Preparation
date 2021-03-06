// Question Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n);
        vector<vector<int>> times(n, vector<int>(n, -1));
        
        for (vector<int> &road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
            
            times[u][v] = time;
            times[v][u] = time;
        }
        
        vector<long long> distances(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        
        distances[0] = 0;
        ways[0] = 1;
        
        long long mod = 1e9 + 7;
        
        priority_queue<vector<long long>, vector<vector<long long>>, greater<>> todo;
        todo.push({ 0, 0 });
        
        while (!todo.empty()) {
            long long totalTimeSoFar = todo.top()[0];
            long long cur = todo.top()[1];
            todo.pop();
            
            if (totalTimeSoFar > distances[cur]) {
                continue;
            }
                
            for (int &neigh : graph[cur]) {
                // Shorter distance found, update the old distance
                long long newTotalTimeSoFar = totalTimeSoFar + times[neigh][cur];
                if (newTotalTimeSoFar < distances[neigh]) {
                    distances[neigh] = newTotalTimeSoFar;
                    ways[neigh] = ways[cur];
                    todo.push({ distances[neigh], neigh });
                }
                else if (newTotalTimeSoFar == distances[neigh]) {
                    ways[neigh] = (ways[neigh] + ways[cur]) % mod;
                }
            }
        }
        
        return ways[n - 1]; 
    }
};