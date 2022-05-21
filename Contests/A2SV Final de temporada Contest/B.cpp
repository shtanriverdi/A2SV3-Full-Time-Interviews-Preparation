#include <bits/stdc++.h>
using namespace std;

void dfs(string cur, unordered_map<string, vector<string>> &graph, unordered_set<string> &seen, string &lastName) {
	seen.insert(cur);
	for (string &neighbor : graph[cur]) {
		if (seen.find(neighbor) == seen.end()) {
			dfs(neighbor, graph, seen, lastName);
		}
	}
	// Last node
	if (graph[cur].empty()) {
		lastName = cur;
	}
}

int main() {
	
	int q;
	cin >> q;

	unordered_map<string, vector<string>> graph;
	unordered_map<string, int> indegrees;
	
	while (q--) {
		string from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to];
		
		indegrees[to]++;
		indegrees[from];
	}

	queue<string> todo;
	for (auto &it : indegrees) {
		if (it.second == 0) {
			todo.push(it.first);
		}
	}
 
	vector<string> result;
	unordered_set<string> seen;
	
	while (!todo.empty()) {
		string from = todo.front(), lastName = "";
		todo.pop();
		
		if (seen.find(from) == seen.end()) {
    		dfs(from, graph, seen, lastName);
    		result.push_back(from + " " + " " + lastName);
		}
	}

	cout << result.size() << "\n";
	for (string &user : result) {
		cout << user << "\n";
	}

	return 0;
}