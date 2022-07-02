import sys
input = sys.stdin.readline

def main():
    field = input()

    n = len(field)
    prefix = [1] * n

    for i in range(1, n):
        if field[i - 1] == field[i]:
            prefix[i] += prefix[i - 1]

    is_dangerous = False
    for count in prefix:
        if count >= 7:
            is_dangerous = True
            break

    if is_dangerous:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()