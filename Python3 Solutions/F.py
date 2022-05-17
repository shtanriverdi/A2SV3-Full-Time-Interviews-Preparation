class TrieNode:
    def __init__(self, char):
        self.letter = char
        self.children = [None] * 3
        self.is_end_of_word = False


def insert(root, word):
    cur = root
    for letter in word:
        index = ord(letter) - ord('a')
        if cur.children[index] == None:
            cur.children[index] = TrieNode(letter)
        cur = cur.children[index]
    
    cur.is_end_of_word = True


def check(query, root):
    for i, original_letter in enumerate(query):
        for ith in range(3):
            letter = chr(ith + ord('a'))
            if letter != query[i]:
                query[i] = letter
                found = search(root, query)
                if found:
                    return True
                query[i] = original_letter
    return False


def hasWord(cur, word_index, word, diff_count):
    if diff_count > 1:
        return False
    
    if (word_index < len(word) and cur.is_end_of_word):
        return False
        
    if (word_index >= len(word) and cur.is_end_of_word == False):
        return False
        
    if word_index == len(word) and cur.is_end_of_word == True and diff_count == 1:
        return True
    
    has_word = False
    for index in range(3):
        if cur.children[index] != None:
            add = 1 if (word_index < len(word) and word[word_index] != chr(index + ord('a'))) else 0
            found = hasWord(cur.children[index], word_index + 1, word, diff_count + add)
                
            if found:
                has_word = True
                break
                
    return has_word

    
def main():
    n, m = map(int, input().split(' '))
    root = TrieNode('*')

    for _ in range(n):
        word = input()
        insert(root, word)

    for _ in range(m):
        query = list(input())
        found = hasWord(root, 0, query, 0)
        if found:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()