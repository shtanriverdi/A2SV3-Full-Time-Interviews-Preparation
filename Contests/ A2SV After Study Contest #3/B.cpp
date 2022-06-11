#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int Ssum = 0, Dsum = 0;

	int l = 0, r = n - 1;

	bool turn = true;

	while (l <= r) {
		if (nums[l] > nums[r]) {

			if (turn) {
				Ssum += nums[l];
			}
			else {
				Dsum += nums[l];
			}
			turn = !turn;

			l++;
		}
		else {
			
			if (turn) {
				Ssum += nums[r];
			}
			else {
				Dsum += nums[r];
			}
			turn = !turn;

			r--;
		}
	}

	cout << Ssum << " " << Dsum << endl;

	return 0;
}