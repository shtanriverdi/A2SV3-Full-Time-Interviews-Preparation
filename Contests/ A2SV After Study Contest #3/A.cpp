#include <bits/stdc++.h>
using namespace std;

int main() {
	
	string sum;
	cin >> sum;

	vector<char> toBeSorted;
	for (char &c : sum) {
		if (c != '+') {
			toBeSorted.push_back(c);
		}
	}

	sort(begin(toBeSorted), end(toBeSorted));
	int len = toBeSorted.size();
	for (int i = 0; i < len; i++) {
		cout << toBeSorted[i];
		if (i != len - 1) {
			cout << "+";
		}
	}

	return 0;
}