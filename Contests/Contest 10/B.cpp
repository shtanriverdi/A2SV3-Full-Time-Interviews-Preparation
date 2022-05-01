#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n, capacity;
	cin >> n >> capacity;

	int litre = 0, spent = 0;
	for (int i = 1; i <= n; i++) {

		int need = min(n - i, capacity);

		if (litre < need) {
		    need -= litre;
			litre += need;
			spent += need * i;
		}
		
		litre--;
	}

	cout << spent;

	return 0;
}