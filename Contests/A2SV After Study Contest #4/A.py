import sys
input = sys.stdin.readline

def main():
    n = int(input())
    answer = 0
    for _ in range(n):
        count = input().count('1')
        if count >= 2:
            answer += 1

    print(answer)

if __name__ == "__main__":
    main()