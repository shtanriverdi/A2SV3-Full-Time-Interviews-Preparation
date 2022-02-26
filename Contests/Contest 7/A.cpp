#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> pre(n, 1);
	for (int i = 1; i <= n; i++) {
	    pre[i - 1] = i;
		pre[i - 1] *= 5;
	}
	
	for (int i = 1; i < n; i++) {
		pre[i] += pre[i - 1];
	}
    
    int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (240 - pre[i] >= k) {
		    ans = i + 1;
			break;
		}
	}
    
    cout << ans << endl;
    
    return 0;
}