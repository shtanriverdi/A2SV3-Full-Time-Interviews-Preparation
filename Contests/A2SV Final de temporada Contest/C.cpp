#include <bits/stdc++.h>
using namespace std;

long long findNumOfPairs(long long K, vector<int> &arr) {
	long long numOfPairsCount = 0;

	unordered_map<long long, int> counts;
	for (int &b : arr) {
		long long wanted = K - b;
		numOfPairsCount += counts[wanted];
		counts[b]++;
	}

	return numOfPairsCount;
}

int main() {
	
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> arr(n, 0);
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}

		long long result = 0;
        long long sum2 = (2 * sum);
		if (sum2 % n == 0) {
			long long K = (sum2 / n);
			result = findNumOfPairs(K, arr);
		}

		cout << result << "\n";
	}

	return 0;
}