#include <bits/stdc++.h>
using namespace std;

void rearrangeQueueAfterTSeconds(int t, string &s) {
	while (t--) {
		vector<vector<int>> swapsToDo; 
		for (int i = 1; i < s.size(); i++) {
			if (s[i - 1] == 'B' && s[i] == 'G') {
				swapsToDo.push_back({ i - 1, i });
			}
		}
		for (vector<int> &toSwap : swapsToDo) {
			swap(s[toSwap[0]], s[toSwap[1]]);
		}
	}
}

int main() {
	
	int n, t;
	cin >> n >> t;

	string s;
	cin >> s;

	rearrangeQueueAfterTSeconds(t, s);
	cout << s;

	return 0;
}