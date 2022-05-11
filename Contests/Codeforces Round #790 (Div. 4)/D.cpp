#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {
	{1, 1}, 
	{-1, -1},
	{1, -1}, 
	{-1, 1}, 
};

bool inside(int i, int j, int &n, int &m) {
	if (i < 0 || i >= n || j < 0 || j >= m) {
		return false;
	}
	return true;
}

void go(int si, int sj, int &n, int &m, vector<int> &dir, int &pointSum, vector<vector<int>> &grid) {

	int ni = si + dir[0];
	int nj = sj + dir[1];

	while(inside(ni, nj, n, m)) {
		pointSum += grid[ni][nj];
		ni += dir[0];
		nj += dir[1];
	}
}

int getPoints(int i, int j, int &n, int &m, vector<vector<int>> &grid) {
	int pointSum = grid[i][j];

	for (vector<int> &dir : dirs) {
		go(i, j, n, m, dir, pointSum, grid);
	}

	return pointSum;
}

int main() {
	
	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> grid(n, vector<int>(m, 0));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}

		int maxPoints = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int point = getPoints(i, j, n, m, grid);
				maxPoints = max(maxPoints, point);
			}
		}

		cout << maxPoints << "\n";
 	}

	return 0;
}