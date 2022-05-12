# Python3 STDIN
"""
import sys
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

1) inp — For taking integer inputs.
2) inlt — For taking List inputs.
3) insr — For taking string inputs. Actually it returns a List of Characters, instead of a string, which is easier to use in Python, because in Python, Strings are Immutable.
4) invr — For taking space seperated integer variable inputs.

The input = sys.stdin.readline is actually for Faster Inputs, because line reading through System STDIN (Standard Input) is faster in Python.
"""

"""
n = int(input())
for i in range(n):
    a, m = map(int, input().split())
    lst = list(map(int, input().split()))
"""

# https://codeforces.com/problemset/problem/25/D

import sys
input = sys.stdin.readline

def main():
    n = int(input()) + 1
    
    dsu = [ i for i in range(n) ]
    rank = [0] * n
    olds = []
    
    for _ in range(2, n):
        a, b = map(int, input().split())
        is_duplicate_edge = union(a, b, dsu, rank)
        if is_duplicate_edge:
            olds.append([a, b])
    
    if not olds:
        print(0)
        sys.exit()
    
    print(len(olds))
    
    p = 2
    while p < n and olds:
        A = find(dsu[p], dsu)
        B = find(dsu[p - 1], dsu)
        union(dsu[p], dsu[p - 1], dsu, rank)
        if A != B:
            ea, eb = olds.pop()
            print(ea, eb, A, B)
        p += 1

def union(a, b, dsu, rank):
    A = find(a, dsu)
    B = find(b, dsu)

    if A == B:
        return True

    dsu[B] = A

    if rank[B] > rank[A]:
        A, B = B, A

    rank[A] += rank[B]
    return False

def find(c, dsu):
    if dsu[c] == c:
        return c
    dsu[c] = find(dsu[c], dsu)
    return dsu[c]

if __name__ == "__main__":
    main()