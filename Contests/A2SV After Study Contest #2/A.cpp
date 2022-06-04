#include <bits/stdc++.h>
using namespace std;

int main() {
	
	string nickname;
	cin >> nickname;

	unordered_map<char, int> counts;
	for (char &c : nickname) {
		counts[c]++;
	}

	int numOfDistincChars = counts.size();
	if (numOfDistincChars % 2 != 0) {
		cout << "IGNORE HIM!";
	}
	else {
		cout << "CHAT WITH HER!";
	}

	return 0;
}