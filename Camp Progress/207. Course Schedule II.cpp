// Question Link: https://leetcode.com/problems/course-schedule-ii/

// DFS Solution 1
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            graph[from].push_back(to);
        }
        
        vector<bool> seen(numCourses, false);
        
        int putIndex = numCourses - 1;
        vector<int> result(numCourses, -1);
        
        for (int ithNode = 0; ithNode < numCourses; ithNode++) {
            if (!seen[ithNode]) {
                vector<bool> seenCycle(numCourses, false);
                bool cycleFound = dfs(ithNode, seen, seenCycle, putIndex, result, graph);
                if (cycleFound) {
                    return {};
                }
            }
        }
        
        return result;
    }
    
    bool dfs(int cur, vector<bool> &seen, vector<bool> &seenCycle, int &putIndex, vector<int> &result, vector<vector<int>> &graph) {
        seen[cur] = true;
        seenCycle[cur] = true;
        bool cycleFound = false;
        for (int &neighbor : graph[cur]) {
            if (seen[neighbor] == false) {
                cycleFound = dfs(neighbor, seen, seenCycle, putIndex, result, graph);
                if (cycleFound) {
                    return true;
                }
            }
            else if (seenCycle[neighbor] == true) {
                return true;
            }
        }
        
        result[putIndex--] = cur;
        seenCycle[cur] = false;
        return false;
    }
};

// DFS Solution 2 Using Unorderd Set
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            graph[from].push_back(to);
        }
        
        vector<bool> seen(numCourses, false);
        int putIndex = numCourses - 1;
        vector<int> result(numCourses, -1);
        
        for (int ithNode = 0; ithNode < numCourses; ithNode++) {
            if (!seen[ithNode]) {
                unordered_set<int> seenCycle;
                bool cycleFound = dfs(ithNode, seen, seenCycle, putIndex, result, graph);
                if (cycleFound) {
                    return {};
                }
            }
        }
        
        return result;
    }
    
    bool dfs(int cur, vector<bool> &seen, unordered_set<int> &seenCycle, int &putIndex, vector<int> &result, vector<vector<int>> &graph) {
        seen[cur] = true;
        seenCycle.insert(cur);
        bool cycleFound = false;
        for (int &neighbor : graph[cur]) {
            if (seen[neighbor] == false) {
                cycleFound = dfs(neighbor, seen, seenCycle, putIndex, result, graph);
                if (cycleFound) {
                    return true;
                }
            }
            else if (seenCycle.find(neighbor) != seenCycle.end()) {
                return true;
            }
        }
        
        result[putIndex--] = cur;
        seenCycle.erase(cur);
        return false;
    }
};


// BFS Solution Kahn's Algorith
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> incomingEdges(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            graph[from].push_back(to);
            incomingEdges[to]++;
        }
        
        queue<int> todo;
        for (int i = 0; i < numCourses; i++) {
            if (incomingEdges[i] == 0) {
                todo.push(i);
            }
        }
        
        vector<int> result;
        int totalCoursesProcesses = 0;
        while (!todo.empty()) {
            int cur = todo.front();
            todo.pop();
            result.push_back(cur);
            totalCoursesProcesses++;
            for (int &neighbor : graph[cur]) {
                incomingEdges[neighbor]--;
                if (incomingEdges[neighbor] == 0) {
                    todo.push(neighbor);
                }
            }
        }
        
        if (totalCoursesProcesses != numCourses) {
            result = {};
        }
        
        return result;
    }
};