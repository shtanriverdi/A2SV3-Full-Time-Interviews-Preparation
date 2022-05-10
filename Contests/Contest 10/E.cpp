#include <bits/stdc++.h>
using namespace std;

int find(int c, vector<int> &dsu) {
	if (dsu[c] == c) {
		return c;
	}
	dsu[c] = find(dsu[c], dsu);
	return dsu[c];
}

bool Union(int a, int b, vector<int> &dsu, vector<int> &rank) {
	int A = find(a, dsu);
	int B = find(b, dsu);

	if (A == B) {
		return false;
	}

	dsu[B] = A;

	if (rank[B] > rank[A]) {
		swap(B, A);
	}

	rank[A] += rank[B];
	return true;
}

int main() {
	
	int n, a, b, t = 0;
	cin >> n;
	
	vector<int> dsu(n + 1);
	for (int i = 1; i <= n; i++) {
		dsu[i] = i;
	}
	
	vector<int> rank(n + 1);
	vector<vector<int>> duplicateEdges;

	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		bool united = Union(a, b, dsu, rank);
		if (united == false) {
			duplicateEdges.push_back({ a, b });
			t++;
		}
	}
	
	cout << t;
	if (duplicateEdges.size() > 0) {
    	for (int i = 2; i <= n; i++) {
    		int A = find(dsu[i], dsu);
    		int B = find(dsu[i - 1], dsu);
    		if (A != B) {
    			cout << "\n" << duplicateEdges.back()[0] << " " << duplicateEdges.back()[1] << " ";
    			cout << i << " " << i - 1;
    			duplicateEdges.pop_back();
    			dsu[B] = A;
    		}
    	}
	}

	return 0;
}