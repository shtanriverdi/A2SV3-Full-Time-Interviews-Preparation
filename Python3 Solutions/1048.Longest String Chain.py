# Question Link: https://leetcode.com/problems/longest-string-chain/
from collections import Counter

class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key = lambda word: len(word))
        
        dp = [[1]]
        words_by_length = [[words[0]]]
        for i in range(1, len(words)):
            if len(words[i]) == len(words_by_length[-1][-1]):
                words_by_length[-1].append(words[i])
                dp[-1].append(1)
            else:
                words_by_length.append([words[i]])
                dp.append([1])
        
        
        longest_chain_length = 1
        for i in range(1, len(words_by_length)):
            for j in range(len(words_by_length[i])):
                for k in range(len(words_by_length[i - 1])):
                    word_a = words_by_length[i][j]
                    word_b = words_by_length[i - 1][k]
                    is_valid_chain = self.isValidChain(word_a, word_b)
                    if is_valid_chain:
                        dp[i][j] = max(dp[i - 1][k] + 1, dp[i][j])
                        longest_chain_length = max(longest_chain_length, dp[i][j])
        
        return longest_chain_length
    
    def isValidChain(self, word_a, word_b):
        len_a = len(word_a)
        len_b = len(word_b)
        
        if len_a - 1 != len_b:
            return False
        
        letter_count_a = Counter(word_a)
        for letter_b in word_b:
            if letter_b not in letter_count_a:
                return False
            letter_count_a[letter_b] -= 1
            if letter_count_a[letter_b] == 0:
                letter_count_a.pop(letter_b)
        
        if len(letter_count_a) != 1:
            return False
        
        remanining_letter = next(iter(letter_count_a))
        for i in range(len(word_a)):
            if word_a[i] == remanining_letter:
                removed_a = word_a[:i] + word_a[i+1:]
                if removed_a == word_b:
                    return True
                
        return False