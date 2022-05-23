#include <bits/stdc++.h>
using namespace std;

bool inside(int i, int j, int &N, int &M) {
	if (i < 0 || i >= N || j < 0 || j >= M) {
		return false;
	}
	return true;
}

void dfs(int i, int j, int &N, int &M, vector<vector<char>> &grid, vector<int> &dirs, int &new_G_count) {

	new_G_count += (grid[i][j] == 'G');

	// Mark cell as visited
	grid[i][j] = '#';

	for (int d = 1; d < 5; d++) {
		int ni = i + dirs[d];
		int nj = j + dirs[d - 1];
		if (inside(ni, nj, N, M) && (grid[ni][nj] == '.' || grid[ni][nj] == 'G')) {
			dfs(ni, nj, N, M, grid, dirs, new_G_count);
		}
	}
}

bool putWalls(int i, int j, int &N, int &M, vector<vector<char>> &grid, vector<int> &dirs) {
	for (int d = 1; d < 5; d++) {
		int ni = i + dirs[d];
		int nj = j + dirs[d - 1];
		if (inside(ni, nj, N, M)) {
			if (grid[ni][nj] == '.') {
				grid[ni][nj] = '#';
			}
			else if (grid[ni][nj] == 'G') {
				return true;
			}
		}
	}

	return false;
}

bool tryToPutWalls(queue<vector<int>> &todo, int &prev_G_count, int &N, int &M, vector<vector<char>> &grid, vector<int> &dirs) {
	while (!todo.empty()) {
		int cur_i = todo.front()[0];
		int cur_j = todo.front()[1];
		todo.pop();

		bool goodPersonFoundAroundBad = putWalls(cur_i, cur_j, N, M, grid, dirs);
		
		// If we had to put wall on escape cell and there was any Good people 
		if (goodPersonFoundAroundBad || (grid[N - 1][M - 1] == '#' && prev_G_count > 0)) {
			return false;
		}
	}
	
	return true;
}

int main() {
	
	int t;
	cin >> t;

	while (t--) {
		int N, M;
		cin >> N >> M;

		int prev_G_count = 0;
		int prev_B_count = 0;

		queue<vector<int>> todo;

		vector<int> dirs = { 0, 1, 0, -1, 0 };

		vector<vector<char>> grid(N, vector<char>(M, '\0'));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> grid[i][j];

				prev_G_count += grid[i][j] == 'G';

				if (grid[i][j] == 'B') {
					prev_B_count++;
					todo.push({ i, j });
				}
			}
		}

		// If there is B on the escape cell
		if (grid[N - 1][M - 1] == 'B') {
			cout << "NO" << "\n";
			continue;
		}

		bool hasPutWallsSucceeded = tryToPutWalls(todo, prev_G_count, N, M, grid, dirs);
		if (hasPutWallsSucceeded == false) {
			cout << "NO" << "\n";
			continue;
		}

		int new_G_count = 0;
		dfs(N - 1, M - 1, N, M, grid, dirs, new_G_count);

		string result = "YES";
		if (new_G_count != prev_G_count) {
			result = "NO";
		}
		
		cout << result << "\n";
	}

	return 0;
}