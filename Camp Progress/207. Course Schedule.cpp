// Question Link: https://leetcode.com/problems/course-schedule

/*
    We need to detect if given graph is DAG (Directed Acyclic Graph)
    To detect that, we need to check if graph has any cycle
*/

// BFS Solution
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegrees(numCourses, 0);
        for (vector<int> &pre : prerequisites) {
            int from = pre[1];
            int to = pre[0];
            graph[from].push_back(to);
            indegrees[to]++;
        }
        
        queue<int> todo;
        for (int i = 0; i < indegrees.size(); i++) {
            if (indegrees[i] == 0) {
                todo.push(i);
            }
        }
        
        int nodesTaken = 0;
        while (!todo.empty()) {
            int cur = todo.front();
            todo.pop();
            nodesTaken++;
            for (int &neighbor : graph[cur]) {
                indegrees[neighbor]--;
                if (indegrees[neighbor] == 0) {
                    todo.push(neighbor);
                }
            }
        }
        
        return nodesTaken == numCourses;
    }
};

// DFS Solution
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build Directed Acyclic Graph
        vector<vector<int>> DAG(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            DAG[from].push_back( to );
        }
        
        vector<bool> seen(numCourses, false);
        for (int ithNode = 0; ithNode < numCourses; ithNode++) {
            if (seen[ithNode] == false) {
                vector<bool> seenForCycle(numCourses, false);
                bool hasCycle = dfs(ithNode, DAG, seen, seenForCycle);
                if (hasCycle) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool dfs(int cur, vector<vector<int>> &DAG, vector<bool> &seen, vector<bool> &seenForCycle) {
        
        seen[cur] = true;
        seenForCycle[cur] = true;
        
        bool hasCycle = false;
        for (int &neighbor : DAG[cur]) {
            if (seen[neighbor] == false) {
                hasCycle = dfs(neighbor, DAG, seen, seenForCycle);
                if (hasCycle) {
                    break;
                }
            }
            else if (seenForCycle[neighbor] == true) {
                hasCycle = true;
                break;
            }
        }
        
        // Backtracking
        seenForCycle[cur] = false;
        
        return hasCycle;
    }
};
