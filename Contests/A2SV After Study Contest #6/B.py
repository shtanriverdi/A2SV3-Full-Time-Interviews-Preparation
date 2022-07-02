import sys
input = sys.stdin.readline

def main():
    n = int(input())
    numbers = list(map(int, input().split()))

    dp = [1] * n
    for i in range(1, n):
        if numbers[i] > numbers[i - 1]:
            dp[i] += dp[i - 1]
    print(max(dp))

if __name__ == "__main__":
    main()