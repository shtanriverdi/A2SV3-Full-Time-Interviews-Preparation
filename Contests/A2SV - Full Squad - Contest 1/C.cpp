#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid(101, vector<int>(101, 0));
vector<vector<int>> prefixSum(101, vector<int>(101, 0));

void preprocess() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			int left = (j - 1) >= 0 ? prefixSum[i][j - 1] : 0;
			int up = (i - 1) >= 0 ? prefixSum[i - 1][j] : 0;
			int upperLeft = ((j - 1) >= 0 && (i - 1) >= 0) ? prefixSum[i - 1][j - 1] : 0;

			prefixSum[i][j] += left + up - upperLeft;
		}
	}
}


int query(int sx, int sy, int ex, int ey) {
	int A = ((sx - 1) >= 0 && (sy - 1) >= 0) ? prefixSum[sx - 1][sy - 1] : 0;
	int C = sy - 1 >= 0 ? prefixSum[ex][sy - 1] : 0;
	int B = sx - 1 >= 0 ? prefixSum[sx - 1][ey] : 0;
	int cornerArea = prefixSum[ex][ey];
    
	int sumArea = cornerArea - B - C + A;

	return sumArea;
}

int main() {
	
	int chairs, hours;
	cin >> chairs >> hours;

	for (int i = 0; i < chairs; i++) {
		int xi, yi;
		cin >> xi >> yi;
		grid[xi][yi]++;
		prefixSum[xi][yi]++;
	}

	preprocess();

	for (int i = 0; i < hours; i++) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		cout << query(sx, sy, ex, ey) << endl;
	}

	return 0;
}