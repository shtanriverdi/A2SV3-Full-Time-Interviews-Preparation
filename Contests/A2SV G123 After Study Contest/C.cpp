#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, vector<vector<int>> &graph, vector<int> &seen) {
	seen[cur] = true;
	for (int &neighbor : graph[cur]) {
		if (seen[neighbor] == false) {
			dfs(neighbor, graph, seen);
		}
	}
}

int main() {
	
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> nodeCost;

	vector<int> cost(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		nodeCost.push_back({ cost[i], i });
	}

	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	sort(begin(nodeCost), end(nodeCost));
	
	vector<int> seen(n + 1, false);
	long long minGold = 0;
	for (pair<int, int> &cur : nodeCost) {
		if (seen[cur.second] == false) {
			minGold += cur.first;
			dfs(cur.second, graph, seen);
		}
	}

	cout << minGold;

	return 0;
}