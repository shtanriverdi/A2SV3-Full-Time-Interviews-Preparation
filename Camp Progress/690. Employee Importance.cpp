// Question Link: https://leetcode.com/problems/employee-importance/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, pair<int, vector<int>>> undirectedGraph;
        for (Employee* &employee : employees) {
            undirectedGraph[employee->id].first = employee->importance;
            undirectedGraph[employee->id].second.insert(undirectedGraph[employee->id].second.end(), begin(employee->subordinates), end(employee->subordinates));
        }
        
        return dfs(undirectedGraph, id);
    }
    
    int dfs(unordered_map<int, pair<int, vector<int>>> &undirectedGraph, int cur) {
        int totalImportance = 0;
        for (int &sub : undirectedGraph[cur].second) {
            totalImportance += dfs(undirectedGraph, sub);
        }
        
        return totalImportance + undirectedGraph[cur].first;
    }
};