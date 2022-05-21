#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin >> n;

	int sum = 0;
	vector<int> coins(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
		sum += coins[i];
	}

	sort(begin(coins), end(coins), greater<int>());

	int minNumOfCoins = 0;
	int yourSum = 0;
	for (int i = 0; i < n && yourSum <= sum; i++) {
		yourSum += coins[i];
		sum -= coins[i];
		minNumOfCoins++;
	}

    cout << minNumOfCoins << "\n";

	return 0;
}