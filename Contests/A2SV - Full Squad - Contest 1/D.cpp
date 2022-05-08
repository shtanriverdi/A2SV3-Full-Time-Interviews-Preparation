#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, int bandwidth, int &maxNode, int &maxBandwith, vector<int> &capacity, vector<vector<int>> &graph) {

	int cap = capacity[cur];
	int numOfKids = graph[cur].size();

	// If we can connect to
	if (numOfKids < cap) {
		int newBandwidth = bandwidth / (numOfKids + 1);
		if (newBandwidth > maxBandwith) {
			maxBandwith = newBandwidth;
			maxNode = cur;
		}
	}

	bandwidth /= numOfKids;

	for (auto &neigh : graph[cur]) {
		dfs(neigh, bandwidth, maxNode, maxBandwith, capacity, graph);
	}
}

int main() {
	
	int routers, students;
	cin >> routers >> students;
	int n = routers + students;

	vector<int> capacity(n, 0);
	vector<int> bandwidth(routers, 0);

	int i = 0;
	for (; i < routers; i++) {
		int cap, band;
		cin >> cap >> band;
		capacity[i] = cap;
		bandwidth[i] = band;
	}

	vector<vector<int>> graph(n);
	for (; i < n; i++) {
		int cap, parent;
		cin >> cap >> parent;

		graph[parent].push_back(i);
		capacity[i] = cap;
	}

	int maxNode = -1, maxBandwith = -1;
	for (int r = 0; r < routers; r++) {
		dfs(r, bandwidth[r], maxNode, maxBandwith, capacity, graph);
 	}

	cout << maxNode;

	return 0;
}