#include <bits/stdc++.h>
using namespace std;

int getSumFirst(string &t) {
	int a = t[0] - '0';
	int b = t[1] - '0';
	int c = t[2] - '0';
	return a + b + c;
}

int getSumLast(string &t) {
	int a = t[3] - '0';
	int b = t[4] - '0';
	int c = t[5] - '0';
	return a + b + c;
}


int main() {
	
	int T;
	cin >> T;

	while (T--) {
		string ticket;
		cin >> ticket;

		int f = getSumFirst(ticket);
		int l = getSumLast(ticket);

		if (f == l) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}