// Question Link: https://leetcode.com/problems/longest-common-prefix/

class Solution {
    struct TrieNode {
        TrieNode* children[26];
        int count = 0;
    };
    
public:
    string longestCommonPrefix(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        int emptyWordCount = 0;
        for (string &word : words) {
            if (word == "") {
                emptyWordCount++;
            }
            insert(root, word);
        }
        
        int branchCount = 0;
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) {
                branchCount++;
            }
        }
        
        if (branchCount != 1 || emptyWordCount > 0) {
            return "";
        }
        
        string longestPrefix = "";        
        queue<pair<TrieNode*, string>> todo;
        todo.push({ root, "" });
        
        while (!todo.empty()) {
            auto[ cur, prefix ] = todo.front();
            todo.pop();
            
            if (prefix.size() > longestPrefix.size()) {
                longestPrefix = prefix;
            }
            
            for (int i = 0; i < 26; i++) {
                if (cur->children[i] != NULL) {
                    if (cur->children[i]->count >= cur->count) {
                        prefix += (i + 'a');
                        todo.push({ cur->children[i], prefix });
                    }
                }
            }
        }
        
        return longestPrefix;
    }
    
    void insert(TrieNode* root, string &word) {
        TrieNode *cur = root;
        for (char &c : word) {
            int index = c - 'a';
            if (cur->children[index] == NULL) {
                cur->children[index] = new TrieNode();
            }
            else {
                cur->children[index]->count++;
            }
            cur = cur->children[index];
        }
    }
};