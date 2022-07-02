import sys
input = sys.stdin.readline

def main():
    lst = input().split()
    n, h = int(lst[0]), int(lst[1])

    friends = list(map(int, input().split()))

    answer = 0
    for friend in friends:
        answer += 1
        if friend > h:
            answer += 1
            
    print(answer)

if __name__ == "__main__":
    main()