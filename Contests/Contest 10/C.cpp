#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int a1, a2;
	cin >> a1 >> a2;

	int min = 0;
	while (a1 > 0 && a2 > 0) {
		if (a1 > a2) {
			bool isEven = (a1 % 2 == 0);
			int rem = a1 / 2;

			int amount = rem - (isEven ? 1 : 0);
			a1 -= 2 * amount;

			min += amount;

			a2 += amount;
			if (amount == 0) {
			    min += isEven;
				break;
			}
		}
		else {
			bool isEven = (a2 % 2 == 0);
			int rem = a2 / 2;

			int amount = rem - (isEven ? 1 : 0);
			a2 -= 2 * amount;

			min += amount;

			a1 += amount;
			if (amount == 0) {
			    min += isEven;
				break;
			}	
		}
	}
	
	cout << min;

	return 0;
}