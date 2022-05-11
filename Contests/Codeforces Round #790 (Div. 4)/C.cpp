#include <bits/stdc++.h>
using namespace std;

int getDiff(string &a, string &b) {
	int totDiff = 0;
	for (int i = 0; i < a.size(); i++) {
		totDiff += abs(a[i] - b[i]);
	}
	return totDiff;
}

int main() {
	
	int T;
	cin >> T;

	while (T--) {
		int n, len;
		cin >> n >> len;

		vector<string> words;
		string word;
		for (int i = 0; i < n; i++) {
			cin >> word;
			words.push_back(word);
		}

		int minnDif = INT_MAX;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				minnDif = min(getDiff(words[i], words[j]), minnDif);
			}
		}

		cout << minnDif << "\n";
 	}

	return 0;
}