// Question Link: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/

// BFS Kahn's Algorithm Solution
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        int n = recipes.size();
        
        unordered_set<string> suppliesSet(begin(supplies), end(supplies));
        suppliesSet.insert(begin(recipes), end(recipes));
        
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegrees;
        
        for (int i = 0; i < n; i++) {
            string recipe = recipes[i];
            indegrees[recipe];
            for (string &ingredient : ingredients[i]) {
                if (suppliesSet.find(ingredient) != suppliesSet.end()) {
                    graph[ingredient].push_back(recipe);                    
                }
                indegrees[recipe]++;
                indegrees[ingredient];
            }
        }
        
        queue<string> todo;
        for (auto &indegree : indegrees) {
            if (indegree.second == 0) {
                todo.push(indegree.first);
            }            
        }
        
        vector<string> result;
        while (!todo.empty()) {
            string cur = todo.front();
            todo.pop();
            for (string &neigh : graph[cur]) {
                indegrees[neigh]--;
                if (indegrees[neigh] == 0) {
                    todo.push(neigh);
                    result.push_back(neigh);
                }
            }
        }
        
        return result;
    }
};

// DFS Coloring Solution
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> color;
        int n = recipes.size();
        for (int i = 0; i < n; i++) {
            string node = recipes[i];
            for (string &neighbor : ingredients[i]) {
                graph[node].push_back(neighbor);
                color[neighbor] = 0;
            }
            color[node] = 0;
        }
        
        unordered_set<string> suppliesSet(begin(supplies), end(supplies));
        vector<string> result;
        unordered_map<string, pair<bool, bool>> memo;
        for (int i = 0; i < n; i++) {
            string cur = recipes[i];
            auto[ cycleFound, canBeMade ] = dfs(cur, graph, color, suppliesSet, memo);
            if (cycleFound == false && canBeMade == true) {
                result.push_back(cur);
            }   
        }
        
        return result;
    }
    
    // COLORS => 0: white(unprocessed), 1: gray(unsafe), 2: black(safe)
    pair<bool, bool> dfs(string cur, unordered_map<string, vector<string>> &graph, unordered_map<string, int> &color, unordered_set<string> &suppliesSet, unordered_map<string, pair<bool, bool>> &memo) {
        
        if (memo.find(cur) != memo.end()) {
            return memo[cur];
        }
        
        bool isRecipe = graph.find(cur) != graph.end();
        bool hasIngredentFound = suppliesSet.find(cur) != suppliesSet.end();
        bool canBeMadeSoFar = (isRecipe == true) || (isRecipe == false && hasIngredentFound);
        
        if (color[cur] > 0) {
            return { color[cur] == 1, canBeMadeSoFar };
        }
        
        color[cur] = 1;
        
        for (string &neigh : graph[cur]) {
            auto[ cycleFound, canBeMade ] = dfs(neigh, graph, color, suppliesSet, memo);
            if (cycleFound || canBeMade == false) {
                return { true, false };
            }
        }
        
        color[cur] = 2;
        memo[cur] = { false, canBeMadeSoFar };
        return memo[cur];
    }
};