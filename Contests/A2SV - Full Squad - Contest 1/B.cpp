#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int T;
	cin >> T;

	while (T--) {
		int students;
		cin >> students;

		vector<int> col(students, 0);
		for (int i = 0; i < students; i++) {
			cin >> col[i];
		}

		int maxx = col.back(), hidings = 0;
		for (int i = students - 2; i >= 0; i--) {
			if (maxx > col[i]) {
				hidings++;
			}
			else if (col[i] > maxx) {
				maxx = col[i];
			}
		}

	    cout << hidings << endl;	
	}

	return 0;
}