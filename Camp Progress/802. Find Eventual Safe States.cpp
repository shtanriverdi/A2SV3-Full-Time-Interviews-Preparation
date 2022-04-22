// Question Link: https://leetcode.com/problems/find-eventual-safe-states/

// BFS Outgoing Edges Solution
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = graph.size();
        
        vector<vector<int>> reverseGraph(n);
        vector<int> outgoingEdgeCounts(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (int &neigh : graph[i]) {
                reverseGraph[neigh].push_back(i);
            }
            outgoingEdgeCounts[i] += graph[i].size();
        }
        
        queue<int> todo;
        for (int i = 0; i < n; i++) {
            if (outgoingEdgeCounts[i] == 0) {
                todo.push(i);
            }
        }
        
        vector<int> result;
        while (!todo.empty()) {
            int cur = todo.front();
            result.push_back(cur);
            todo.pop();
            for (int &neigh : reverseGraph[cur]) {
                outgoingEdgeCounts[neigh]--;
                if (outgoingEdgeCounts[neigh] == 0) {
                    todo.push(neigh);
                }
            }
        }
        
        sort(begin(result), end(result));
        return result;
    }
};

// DFS Cycle Detectoin Solution
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> safeNodes(n, true);
        vector<int> seen(n, false);
        for (int i = 0; i < n; i++) {
            if (safeNodes[i]) {
                unordered_set<int> nodesInCycle;
                bool hasCycle = dfs(i, graph, seen, nodesInCycle);
                if (hasCycle) {
                    // Discard unsafeNodes
                    for (auto &unsafeNode : nodesInCycle) {
                        safeNodes[unsafeNode] = false;
                        seen[unsafeNode] = false;
                    }
                }
            }
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (safeNodes[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
    
    bool dfs(int cur, vector<vector<int>> &graph, vector<int> &seen, unordered_set<int> &nodesInCycle) {
        seen[cur] = true;
        nodesInCycle.insert(cur);
        
        for (int &neighbor : graph[cur]) {
            if (seen[neighbor] == false) {
                bool hasCycle = dfs(neighbor, graph, seen, nodesInCycle);
                if (hasCycle) {
                    return true;
                }
            }
            else if (nodesInCycle.find(neighbor) != nodesInCycle.end()) {
                return true;
            }
        }       
        
        // For safe nodes
        nodesInCycle.erase(cur);
        return false;
    }
};