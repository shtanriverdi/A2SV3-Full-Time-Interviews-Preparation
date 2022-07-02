import sys, heapq
input = sys.stdin.readline

def main():
    nodes, edges = list(map(int, input().split()))

    graph = [ [] for _ in range(nodes + 1) ]
    seen = [False] * (nodes + 1)

    for i in range(edges):
        a, b = list(map(int, input().split()))
        graph[a].append(b)
        graph[b].append(a)

    todo = [ 1 ]
    seen[1] = True

    sequence = []

    while todo:
        cur = heapq.heappop(todo)
        sequence.append(cur)
        for neighbor in graph[cur]:
            if seen[neighbor] == False:
                heapq.heappush(todo, neighbor)
                seen[neighbor] = True

    for s in sequence:
        print(s,end=" ")


if __name__ == "__main__":
    main()