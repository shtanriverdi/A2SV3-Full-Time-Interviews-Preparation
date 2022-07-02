import sys
input = sys.stdin.readline

def main():
    word = input()
    n = len(word)
    
    clean = []
    if word[0] == 'u' or word[0] == 'n':
        clean = [[ word[0], 1 ]]

    # m, w check
    has_m_w = False
    if word[0] == 'm' or word[0] == 'w':
        has_m_w = True
    
    has_no_consecutive = True
    for i in range(1, n):
        prev_letter = word[i - 1]
        curr_letter = word[i]
        if prev_letter == 'm' or prev_letter == 'w' or curr_letter == 'm' or curr_letter == 'w':
            has_m_w = True
            break
        
        elif (curr_letter == 'u' or curr_letter == 'n') and curr_letter == prev_letter:
            has_no_consecutive = False
            if len(clean) > 0 and clean[-1][0] == curr_letter:
                clean[-1][1] += 1
            else:
                clean.append([curr_letter, 2])
            
    if has_m_w:
        print(0)
        sys.exit()

    if has_no_consecutive:
        print(1)
        sys.exit()

    print(clean)
    MOD = 1000000007
    ans = 0
    for i in range(1, len(clean)):
        count_prev = clean[i - 1][1]
        count_curr = clean[i][1]
        ans += (count_prev * count_curr) % MOD
    
    if len(clean) == 1:
        ans = clean[0][1]
    
    print(ans)
    
if __name__ == "__main__":
    main()