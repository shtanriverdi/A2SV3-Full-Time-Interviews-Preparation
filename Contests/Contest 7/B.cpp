#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
    

    vector<vector<int>> zip = { { A[0], 1 } };
	for (int i = 1; i < n; i++) {
		if (zip.back()[0] == A[i]) {
			zip.back()[1]++;
		}
		else {
			zip.push_back({ A[i], 1 });
		}
	}

    int ans = 2;
	for (int i = 1; i < zip.size(); i++) {
		if (zip[i][0] != zip[i - 1][0]) {
			ans = max(ans, 2 * min(zip[i][1], zip[i - 1][1]));
		}
	}

    cout << ans << endl;
    
    return 0;
}