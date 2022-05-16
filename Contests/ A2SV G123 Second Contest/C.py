import sys
input = sys.stdin.readline

def main():
    n = int(input())
    print(bin(n).count("1"))

if __name__ == "__main__":
    main()