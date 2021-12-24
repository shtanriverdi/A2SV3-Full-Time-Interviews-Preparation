// Question Link: https://codeforces.com/problemset/problem/1/A

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, a;
	cin >> n >> m >> a;

    int sideN = (n / a);
    sideN += (n % a) > 0;
    
    int sideM = (m / a);
    sideM += (m % a) > 0;
    
    cout << sideN * (long long int) sideM;

	return 0;
}