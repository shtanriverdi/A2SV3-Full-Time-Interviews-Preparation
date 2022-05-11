#include <bits/stdc++.h>
using namespace std;

int binarySearch(int query, vector<int> &candies) {
	int len = candies.size();
	int l = 0, r = candies.size() - 1, m;
	while (l < r) {
		m = (r + l) / 2;
		if (candies[m] >= query) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}

	int sum = candies[l];
	int count = l + 1;

	return sum >= query ? count : -1;
}

int main() {
	
	int T;
	cin >> T;

	while (T--) {

		int n, q;
		cin >> n >> q;

		vector<int> candies;
		for (int i = 0; i < n; i++) {
			int candy;
			cin >> candy;
			candies.push_back(candy);
		}

		sort(begin(candies), end(candies), greater<int>());

		// Prefix sum
		for (int i = 1; i < n; i++) {
			candies[i] += candies[i - 1];
		}

		for (int i = 0; i < q; i++) {
			int query;
			cin >> query;
			cout << binarySearch(query, candies) << "\n";
		}
 	}

	return 0;
}