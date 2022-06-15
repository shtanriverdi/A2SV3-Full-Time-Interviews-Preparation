def main():
    t = int(input())
    for i in range(t):
        lists = list(input().split('R'))
        answer = 0
        for l in lists:
            answer = max(answer, len(l) + 1)
        print(answer)

if __name__ == "__main__":
    main()