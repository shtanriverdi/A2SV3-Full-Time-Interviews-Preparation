#include <bits/stdc++.h>
using namespace std;

int main() {
	
	string n;
	cin >> n;

	for (int i = n.size() - 1; i >= 0; i--) {
		n += n[i];
	}

	cout << n;
	
	return 0;
}