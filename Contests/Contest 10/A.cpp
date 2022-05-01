#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int T;
	cin >> T;

	while (T--) {
		int n, tmp;
		cin >> n;
		unordered_map<int, int> counts;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			counts[tmp]++;
		}

		int res = -1;
		for (auto &it : counts) {
			if (it.second >= 3) {
				res = it.first;
				break;
			}
		}

	    cout << res << "\n";
	}

	return 0;
}