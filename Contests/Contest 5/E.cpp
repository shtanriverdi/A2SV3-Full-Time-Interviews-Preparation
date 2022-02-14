#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n, ith = 2, parentNum;
	cin >> n;

	n--;

	unordered_map<int, vector<int>> treeMap;
	while (n--) {
	    cin >> parentNum;
		treeMap[parentNum].push_back(ith);
		ith++;
	}

	queue<int> todo;
	todo.push(1);
	while (!todo.empty()) {
		int node = todo.front();
		todo.pop();

		// Non-leaf
		if (treeMap[node].size() != 0) {
			// Check if this node has at least 3 leaf node
			int leafCount = 0;
			for (int &kid : treeMap[node]) {
				if (treeMap[kid].size() == 0) {
					leafCount++;
				}
				if (leafCount >= 3) {
					break;
				}
			}
			if (leafCount < 3) {
				cout << "No";
				return 0;
			}
		} 

		for (int &kid : treeMap[node]) {
			todo.push(kid);			
		}
	}

	cout << "Yes";
	return 0;
}