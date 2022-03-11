#include <bits/stdc++.h>
using namespace std;

int getStepsToReachTarget(int &target, int start) {
	int steps = 0;
	if (start == target) {
		return steps;
	}
	if (start < target) {
		while (start < target) {
			start += 4;
			steps++;
		}

		while (start > target) {
			start--;
			steps++;
		}

	}
	// start > target
	else {
		while (start > target) {
			start--;
			steps++;
		}
	}

	return steps;
}

int main() {
	
	int T;
	cin >> T;

	while (T--) {
		int k;
		cin >> k;
		int a31 = getStepsToReachTarget(k, 31);
		int b32 = getStepsToReachTarget(k, 32);
		if (a31 < b32) {
			cout << "31" << endl;
		}
		else {
			cout << "32" << endl;
		}
	}

	return 0;
}