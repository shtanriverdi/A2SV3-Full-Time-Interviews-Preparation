#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
	TrieNode* kids[3];
	bool isEnd = false;
};

void insert(TrieNode *root, string &word) {
	TrieNode *cur = root;
	for (char &c : word) {
		int index = c - 'a';
		if (cur->kids[index] == NULL) {
			cur->kids[index] = new TrieNode();
		}
		cur = cur->kids[index];
	}
	cur->isEnd = true;
}

bool dfs(TrieNode *cur, string &query, int &queryLen, int queryIdx, int diffCount) {

	if (diffCount > 1) {
		return false;
	}

	if (queryIdx == queryLen && cur->isEnd == false) {
		return false;
	}

	if (queryIdx < queryLen && cur->isEnd == true) {
		return false;
	}

	if (queryIdx == queryLen && cur->isEnd == true) {
		return diffCount == 1;
	}

	bool found = false;
	for (int i = 0; i <= 2; i++) {

		if (cur->kids[i] != NULL) {
			char curLetter = i + 'a';
			char queryLetter = query[queryIdx];
			bool validQueryIndex = queryIdx < queryLen;
			int diffAdd = (validQueryIndex && curLetter != queryLetter) ? 1 : 0;

			found = dfs(cur->kids[i], query, queryLen, queryIdx + 1, diffCount + diffAdd);
			if (found) {
				break;
			}
		}
	}

	return found;
}

int main() {
	
	int n, m;
	cin >> n >> m;

	TrieNode *root = new TrieNode();

	while (n--) {
		string word;
		cin >> word;
		insert(root, word);
	}
	
	while (m--) {
		string query;
		cin >> query;
		int queryLen = query.size();
		bool found = dfs(root, query, queryLen, 0, 0);
		if (found) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}