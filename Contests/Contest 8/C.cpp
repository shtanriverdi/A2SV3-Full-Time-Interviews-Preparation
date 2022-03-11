#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int days, assistants;
	cin >> days >> assistants;

	vector<vector<int>> intervals;
	vector<int> range(2);
	for (int i = 0; i < assistants; i++) {
		cin >> range[0] >> range[1];
		intervals.push_back(range);
	}

	sort(begin(intervals), end(intervals));

	if (intervals[0][0] != 0) {
		cout << "YES" << endl;
		return 0;
	}

	int curIndex = intervals[0][1];
	for (int i = 1; i < intervals.size(); i++) {
		int curStart = intervals[i][0];
		int curEnd = intervals[i][1];
		if (curStart - curIndex > 1) {
			cout << "YES" << endl;
			return 0;
		}

		curIndex = max(curIndex, curEnd);
	}

	if (curIndex != days - 1) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}