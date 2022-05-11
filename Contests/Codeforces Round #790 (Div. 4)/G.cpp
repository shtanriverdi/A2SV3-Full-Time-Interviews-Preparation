#include <bits/stdc++.h>
using namespace std;

vector<int> dfs(int cur, vector<vector<int>> &graph, string &str, int &balancedCnt) {
	
	vector<int> cnt = { 0, 0 }; // {W_Cnt, B_cnt}

	for (int &neigh : graph[cur]) {
		vector<int> sub = dfs(neigh, graph, str, balancedCnt);
		cnt[0] += sub[0];
		cnt[1] += sub[1];
	}

	if (str[cur] == 'W') {
		cnt[0] += 1;
	}
	else if (str[cur] == 'B') {
		cnt[1] += 1;
	}

	if (cnt[0] == cnt[1]) {
		balancedCnt++;
	}

	return cnt;
}

int main() {
	
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		n += 1;

		vector<vector<int>> graph(n);

		for (int child = 2; child < n; child++) {
			int parent;
			cin >> parent;
			graph[parent].push_back(child);
		}

		string str, tmp;
		cin >> tmp;
		str = "." + tmp;

		int balancedCnt = 0;
		dfs(1, graph, str, balancedCnt);
		cout << balancedCnt << "\n";
	}

	return 0;
}