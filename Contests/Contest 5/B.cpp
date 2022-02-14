#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n, m, k, i = 0;
	cin >> n >> m >> k;

	vector<int> nums(n, 0);
	while (n--) {
	    cin >> nums[i++];
	}

	sort(begin(nums), end(nums), greater<int>());
	long long int maxx = nums[0];
	long long int secondMax = nums[1];
	
	long long int rem = m % (k + 1);

	long long int numOfSubArraysFillled = m / (k + 1);

	long long int oneSubArraySum = (maxx * k) + secondMax;

	long long int res = numOfSubArraysFillled * oneSubArraySum;

	res += rem * maxx;

	cout << res;
		
	return 0;
}