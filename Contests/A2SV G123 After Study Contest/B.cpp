#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin >> t;

	vector<int> pows;
	
	unordered_map<int, int> answerMap;
	for (int i = 0; i < 31; i++) {
	    int pow2 = pow(2, i);
		pows.push_back( pow2 );
		answerMap[pow2] = pow2 - 1;
	}
	
	while (t--) {
		int num;
		cin >> num;
		
        auto it = lower_bound(begin(pows), end(pows), num);
        
        if (answerMap.find(num) == answerMap.end()) {
            it = prev(it);
        }
        
		cout << answerMap[*it] << "\n";
	}

	return 0;
}