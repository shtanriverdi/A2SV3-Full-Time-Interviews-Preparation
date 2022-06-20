# Question Link: https://leetcode.com/problems/short-encoding-of-words/
class TrieNode:
    def __init__(self):
        self.kids = [None] * 26
        self.is_end_of_word = False

class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        root = TrieNode()
        for word in words:
            self.insert(root, word)
            
        result = [0]
        self.dfs(root, result, 0)
        return result[0]
   
    def dfs(self, cur, result, counter):
        for kid in cur.kids:
            if kid is not None:
                self.dfs(kid, result, counter + 1)
                
        if cur.is_end_of_word == True:
            result[0] += counter + 1
            
    def insert(self, root, word):
        cur = root
        is_prefix = True
        for letter in reversed(word):
            index = ord(letter) - 97
            if cur.kids[index] is None:
                cur.kids[index] = TrieNode()
                is_prefix = False
                
            cur.is_end_of_word = False
            cur = cur.kids[index]
            
        if is_prefix == False:
            cur.is_end_of_word = True