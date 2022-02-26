#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &A, int target) {
	int l = 0, r = A.size() - 1, m, ans = 0;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (target >= A[m]) {
			l = m + 1;
			ans = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	return ans;
}

int main() {
	int n;
	cin >> n;

	vector<int> prices(n);
	for (int i = 0; i < n; i++) {
		cin >> prices[i];
	}
    
	sort(begin(prices), end(prices));

    int days;
	cin >> days;
	for (; days > 0; days--) {
		int coin, answer;
		cin >> coin;
        answer = binarySearch(prices, coin);
        cout << answer << endl;
	}

    return 0;
}