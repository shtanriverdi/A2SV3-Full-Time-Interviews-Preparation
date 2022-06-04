#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin >> n;

	vector<int> ai(n);
	for (int i = 0; i < n; i++) {
		cin >> ai[i];
	}

	vector<int> diff(n);

	vector<int> bi(n);
	for (int i = 0; i < n; i++) {
		cin >> bi[i];
		diff[i] = ai[i] - bi[i];
	}

	// MISTAKE
	// int numOfGoodPairs = 0;
	/*
		n = 200.000
		if all numbers are positive in diff array,
		we'll have;
		(n * (n + 1)) / 2 = 20.000.100.000 ~ 20 Billion
		which cannot fit in an integer...
	*/

	// SOLUTION
	long long numOfGoodPairs = 0;

	sort(begin(diff), end(diff));
	
	if (diff.back() <= 0) {
		cout << numOfGoodPairs;
	}
	else {
		
		for (int i = 0; i < n; i++) {
			// If already positive
			if (diff[i] > 0) {
				numOfGoodPairs += n - i - 1;
			}
			else {
				int wanted = abs(diff[i]) + 1;
				auto it = lower_bound(begin(diff), end(diff), wanted);

				int foundIndex = it - diff.begin();

				numOfGoodPairs += n - foundIndex;
			}

		}

		cout << numOfGoodPairs;
	}


	return 0;
}