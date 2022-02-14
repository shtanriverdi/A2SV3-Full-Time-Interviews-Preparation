#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int T;
	cin >> T;

	while (T--) {
		string s;
	    cin >> s;

	    vector<pair<char, int>> zip;
	    for (char c : s) {
	    	if (!zip.empty() && zip.back().first == c) {
	    		zip.back().second++;
	    	}
	    	else {
	    		zip.push_back({ c, 1 });
	    	}
	    }

		set<char> st;
	    for (auto &pair : zip) {
	    	int count = pair.second;
	    	if (count % 2 == 1) {
	    	    st.insert(pair.first);
	    	}
	    }

	    string res;
	    for (auto &it : st) {
            res += it;
	    }

	    cout << res << "\n";
	}

	return 0;
}