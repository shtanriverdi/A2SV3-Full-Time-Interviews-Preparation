#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> intervals(n, vector<int>(2, 0));

		for (int i = 0; i < n; i++) {
			cin >> intervals[i][0];
		}

		vector<int> fi(n);
		for (int i = 0; i < n; i++) {
			cin >> intervals[i][1];
		}

		vector<int> prev = intervals[0];

		vector<int> durations(n, 0);
		durations[0] = prev[1] - prev[0];

		for (int i = 1; i < n; i++) {

			int prevStart = prev[0];
			int prevEnd = prev[1];

			int curStart = intervals[i][0];
			int curEnd = intervals[i][1];

			// Overlaps
			if (prevStart <= curStart && curStart <= prevEnd) {
				if (curEnd > prevEnd) {
					durations[i] = curEnd - prevEnd;
					prev = intervals[i];
				}
			}
			else {
				// Update prev
				if (curEnd > prevEnd) {
					prev = intervals[i];
				}
				durations[i] = prev[1] - prev[0];
			}
		}

		for (int i = 0; i < n; i++) {
			cout << durations[i] << " ";
		}
		cout << endl;
	}

	return 0;
}