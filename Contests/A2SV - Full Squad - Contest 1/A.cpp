#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int T;
	cin >> T;

	while (T--) {
		int n, m, p = 2, used = 0;
	    cin >> n >> m;

	    priority_queue<int> pq;
	    while (m--) {
	    	int ai;
	    	cin >> ai;
	    	pq.push(ai);
	    }

	    while (p < n) {
	    	if (pq.empty()) {
				used = -1;
	    		break;
	    	}

	    	int ai = pq.top();
	    	pq.pop();

	    	p += ai - 1;
	    	used++;
 	    }

	    cout << used << endl;	
	}

	return 0;
}