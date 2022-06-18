import sys
input = sys.stdin.readline

sys.setrecursionlimit(4000)

def dfs(cur, graph, info, num_of_balanceds):

    w_b_count = [0, 0]

    for neighbor in graph[cur]:
        temp = [0, 0]
        temp = dfs(neighbor, graph, info, num_of_balanceds)
        w_b_count[0] += temp[0]
        w_b_count[1] += temp[1]

    if info[cur] == 'W':
        w_b_count[0] += 1
    elif info[cur] == 'B':
        w_b_count[1] += 1

    if w_b_count[0] == w_b_count[1]:
        num_of_balanceds[0] += 1

    return w_b_count


def main():
    t = int(input())

    for _ in range(t):

        n = int(input())

        graph = [ [] for _ in range(n+1) ]
        
        parents = list(map(int, input().split()))
        
        ith_node = 2
        for parent in parents:
            graph[parent].append(ith_node)
            ith_node += 1

        info = ['0'] + list(input())
        
        num_of_balanceds = [0]
        dfs(1, graph, info, num_of_balanceds)

        print(num_of_balanceds[0])


if __name__ == "__main__":
    main()