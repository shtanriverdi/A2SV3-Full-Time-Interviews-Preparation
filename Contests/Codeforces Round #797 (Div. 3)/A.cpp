#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int a = (n / 3) + (n % 3);

		int b = n / 3;

		int c = n / 3;

		c--;
		b++;

		if (n % 3 != 2) {
			a++;
			b--;
		}

	    cout << b << " " << a << " " << c << "\n";
	}

	return 0;
}