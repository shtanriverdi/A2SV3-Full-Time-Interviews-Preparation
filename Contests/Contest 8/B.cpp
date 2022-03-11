#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &canSolve, int target) {
	int len = canSolve.size(), half = len / 2;
	int l = 0, r = len - 1, m;
	while (l < r) {
		m = l + (r - l) / 2;
		if (canSolve[m] >= target) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}

	int count = len - l;

	return count > half && count != len;
}

int main() {
	
	int n, m;
	cin >> n >> m;

	vector<int> canSolve(m);
	for (int i = 0; i < m; i++) {
		cin >> canSolve[i];
	}

	sort(begin(canSolve), end(canSolve));

	int diff;
	for (int i = 0; i < n; i++) {
		cin >> diff;
		if (binarySearch(canSolve, diff)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}