#include <bits/stdc++.h>
using namespace std;

bool inside(int i, int j, int &R, int &C) {
	if (i < 0 || i >= R || j < 0 || j >= C) {
		return false;
	}
	return true;
}

void dfs(int &count, int i, int j, vector<vector<vector<int>>> &grid, vector<vector<bool>> &seen, int &R, int &C, unordered_map<int, vector<int>> &dirMap) {
	seen[i][j] = true;
	for (int &dirNum : grid[i][j]) {
	    vector<int> dir = dirMap[dirNum];
	    int ni = i + dir[0];
	    int nj = j + dir[1];
	    if (inside(ni, nj, R, C) && seen[ni][nj] == false) {
    	   dfs(count, ni, nj, grid, seen, R, C, dirMap);
    	   count++;
	    }
	}
} 

int main() {

	unordered_map<char, int> signMap = {
		{'>', 1},
		{'<', 3},
		{'v', 2},
		{'^', 0},
	};
	
	unordered_map<int, vector<int>> dirMap = {
		{1, {0, 1}},
		{3, {0, -1}},
		{2, {1, 0}},
		{0, {-1, 0}},
	};
	
	int row, col;
	cin >> row >> col;

	vector<vector<vector<int>>> grid(row, vector<vector<int>>(col));

	// For each ROW
	string r;
	cin >> r;
	for (int i = 0; i < row; i++) {
		char dirKey = r[i];
		int sign = signMap[dirKey];
		for (int k = 0; k < col; k++) {
			grid[i][k].push_back(sign);
		}
	}

	// For each COLUMN
	string c;
	cin >> c;
	for (int j = 0; j < col; j++) {
		char dirKey = c[j];
		int sign = signMap[dirKey];
		for (int k = 0; k < row; k++) {
			grid[k][j].push_back(sign);
		}
	}

    // Run DFS for each node
	string result;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
	        vector<vector<bool>> seen(row, vector<bool>(col, false));
		    int count = 0;
			dfs(count, i, j, grid, seen, row, col, dirMap);
			if (count != ((row * col) - 1)) {
			    cout << "NO";
			    return 0;
			}
		}
	}

	cout << "YES";

	return 0;
}