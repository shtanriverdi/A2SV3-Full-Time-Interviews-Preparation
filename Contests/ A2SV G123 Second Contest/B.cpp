#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int &len) {
	for (int i = 0; i < len / 2; i++) {
		if (s[i] != s[len - i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		unordered_map<char, int> count;
		for (char &c : s) {
			count[c]++;
		}

		int len = s.size();
		if (count['a'] == len) {
			cout << "NO" << endl;
		}
		else {
			bool palindrome = isPalindrome(s, len);
			if (palindrome) {
				cout << "YES" << endl;
				s += 'a';
				cout << s << endl;
			}
			else {
				string s2 = s + "a";
				len++;
				bool palindrome2 = isPalindrome(s2, len);
				cout << "YES" << endl;
				if (palindrome2) {
					s2.pop_back();
					cout << ("a" + s2)  << endl;
				}
				else {
					cout << s2 << endl;
				}
			}
		}
	}

	return 0;
}