// Question Link: https://leetcode.com/problems/accounts-merge/

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int len = accounts.size();
        vector<int> dsu(len, 0);
        vector<int> height(len, 1);
        for (int i = 0; i < len; i++) {
            dsu[i] = i;
        }
        
        unordered_map<string, int> emailToParentMap;
        for (int i = 0; i < len; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToParentMap.find(email) == emailToParentMap.end()) {
                    emailToParentMap[email] = i;
                }
                else {
                    Union(i, emailToParentMap[email], dsu, height);
                }   
            }
        }
        
        unordered_map<int, vector<string>> emailGroupMap;
        for (auto &it : emailToParentMap) {
            int parentIndex = find(dsu[it.second], dsu);
            emailGroupMap[parentIndex].push_back(it.first);
        }

        vector<vector<string>> result;
        for (auto &it : emailGroupMap) {
            int parentIndex = it.first;
            string name = accounts[parentIndex][0];
            sort(begin(it.second), end(it.second));
            vector<string> emails = { name };
            emails.insert(emails.end(), it.second.begin(), it.second.end());
            result.push_back(emails);
        }        
        
        return result;
    }
    
    int find(int cur, vector<int> &dsu) {
        if (cur == dsu[cur]) {
            return cur;
        }
        dsu[cur] = find(dsu[cur], dsu);
        return dsu[cur];
    }
    
    void Union(int &a, int &b, vector<int> &dsu, vector<int> &height) {
        int A = find(a, dsu);
        int B = find(b, dsu);
        if (A == B) {
            return;
        }
        
        if (height[A] < height[B]) {
            dsu[A] = dsu[B];
        }
        else if (height[A] > height[B]) {
            dsu[B] = dsu[A];
        }
        else {
            dsu[B] = dsu[A];
            height[A]++;
        }
    }
};