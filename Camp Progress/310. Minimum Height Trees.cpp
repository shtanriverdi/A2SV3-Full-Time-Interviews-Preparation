// Question Link: https://leetcode.com/problems/minimum-height-trees/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return { 0 };
        }
        
        unordered_map<int, unordered_set<int>> graph;
        vector<int> edgeCount(n, 0);
        for (vector<int> &edge : edges) {
            int a = edge[0];
            int b = edge[1];
            graph[a].insert(b);
            graph[b].insert(a);
            edgeCount[a]++;
            edgeCount[b]++;
        }
        
        queue<int> leaves;
        for (int i = 0; i < edgeCount.size(); i++) {
            if (edgeCount[i] == 1) {
                leaves.push(i);
            }
        }
        
        while (leaves.size() > 0) {
            if (graph.size() <= 2) {
                break;
            }
            for (int k = leaves.size(); k > 0; k--) {
                int cur = leaves.front();
                leaves.pop();
                
                int parent = *graph[cur].begin();
                
                graph.erase(cur);
                graph[parent].erase(cur);
                edgeCount[parent]--;
                
                if (edgeCount[parent] == 1) {
                    leaves.push(parent);
                }
            }
        }
        
        vector<int> result;
        if (graph.size() == 2) {
            result.push_back(graph.begin()->first);
            result.push_back(next(graph.begin(), 1)->first);
        }
        else {
            result.push_back(graph.begin()->first);
        }

        return result;
    }
};