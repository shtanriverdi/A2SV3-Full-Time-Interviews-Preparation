#include <bits/stdc++.h>
using namespace std;

void fillAllColumns(int num, vector<vector<int>> &prefixSum) {
	int row = num;
	int columIndexInBinaryForm = pow(2, 0);
	int columIndex = 0;

	for (int times = 0; times < 19; times++) {

		bool zeroFound = ((num & columIndexInBinaryForm) == 0);
		prefixSum[row][columIndex] += prefixSum[row - 1][columIndex] + zeroFound;

		columIndex += 1;
		columIndexInBinaryForm = pow(2, columIndex);
	}
}

void preProcess(vector<vector<int>> &prefixSum) {
	for (int num = 1; num < 200001; num++) {
		fillAllColumns(num, prefixSum);
	}
}

int getMinNumberOfZerosInRange(int &left, int &right, vector<vector<int>> &prefixSum) {
	int localMinNumOfZeros = INT_MAX;
	for (int columIndex = 0; columIndex <= 18; columIndex++) {
		int numOfZerosAtCurrentColumn = prefixSum[right][columIndex] - prefixSum[left - 1][columIndex];
		localMinNumOfZeros = min(numOfZerosAtCurrentColumn, localMinNumOfZeros);
	}

	return localMinNumOfZeros;
}

int main() {
	
	int T;
	cin >> T;

	vector<vector<int>> prefixSum(200001, vector(32, 0));
	preProcess(prefixSum);

	while (T--) {
		int l, r;
		cin >> l >> r;
		cout << getMinNumberOfZerosInRange(l, r, prefixSum) << "\n";
	}

	return 0;
}