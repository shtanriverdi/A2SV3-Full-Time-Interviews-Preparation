import sys
input = sys.stdin.readline

def main():
    n = int(input())
    numbers = list(map(int, input().split()))

    box_count = int(input())
    for _ in range(box_count):
        wi, hi = map(int, input().split())

        max_height = max(numbers[0], numbers[wi - 1])
        numbers[0] = max_height + hi

        print(max_height)
        print("numbers:",numbers,"max_height:",max_height)


if __name__ == "__main__":

    main()