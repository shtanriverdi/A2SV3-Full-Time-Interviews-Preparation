#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int x;
	cin >> x;

    int numOfOnes = 0;
	while (x > 0) {
	    numOfOnes += x & 1;
	    x = x >> 1;
	}

	cout << numOfOnes << endl;

	return 0;
}