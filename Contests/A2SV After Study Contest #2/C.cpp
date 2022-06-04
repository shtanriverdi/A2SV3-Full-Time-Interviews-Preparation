#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin >> n;

	unordered_map<string, int> database;
	
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;

		if (database.find(name) == database.end()) {
			database[name] = 0;
			cout << "OK\n";
		}
		else {
			
			int value = database[name];
			database[name] = value + 1;

			int newValue = database[name];

			cout << name << newValue << "\n";
		}

	}

	return 0;
}