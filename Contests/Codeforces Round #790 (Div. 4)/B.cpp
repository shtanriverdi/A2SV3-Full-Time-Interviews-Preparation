#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int T;
	cin >> T;

	while (T--) {

		int n, minn = INT_MAX;
		cin >> n;

		vector<int> candies(n, 0);

		for (int i = 0; i < n; i++) {
			cin >> candies[i];
			minn = min(minn, candies[i]);
		}

		int eaten = 0;
		for (int &candy : candies) {
			eaten += abs(candy - minn);
		}

		cout << eaten << endl;
 	}

	return 0;
}