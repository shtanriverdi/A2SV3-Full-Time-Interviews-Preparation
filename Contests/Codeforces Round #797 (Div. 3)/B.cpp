#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> A(n);
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}

		int maxDiff = 0;
		bool negativeFound = false;

		vector<int> B(n);
		for (int i = 0; i < n; i++) {
			cin >> B[i];

			int diff = A[i] - B[i];
			
			negativeFound |= diff < 0;

			maxDiff = max(maxDiff, diff);
		}

		if (negativeFound) {
			cout << "NO\n";
		}

		else {
			bool valid = true;
			
			for (int i = 0; i < n; i++) {
				int check = A[i] - maxDiff;
				if (check != B[i] && B[i] != 0) {
					valid = false;
					break;
				}
			}

			if (valid) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}