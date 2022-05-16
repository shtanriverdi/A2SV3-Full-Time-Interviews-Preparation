#include <bits/stdc++.h>
using namespace std;

int main() {
	
	string A, B;
	cin >> A >> B;

	int lenA = A.size();
	int lenB = B.size();

	int ai = lenA - 1;
	int bi = lenB - 1;

	if (A[ai] != B[bi]) {
		cout << lenA + lenB << endl;
	}
	else {
		while (ai >= 0 && bi >= 0 && A[ai] == B[bi]) {
			ai--;
			bi--;
		}

		cout << (ai + 1) + (bi + 1) << endl;
	}

	return 0;
}