import queue

def minEdgeBFS(edges, v, n):
    visited = [0] * n
    distance = [-1] * n
    Q = queue.Queue()
    distance[0] = 0
    Q.put(0)
    visited[0] = True
    while (not Q.empty()):
        x = Q.get()
        for i in range(len(edges[x])):
            if (visited[edges[x][i]]):
                continue

            # update distance for i
            distance[edges[x][i]] = distance[x] + 1
            Q.put(edges[x][i])
            visited[edges[x][i]] = 1
    return distance[v]

for _ in range(int(input())):
    N, K = map(int, input().split())
    S = []
    for i in range(N):
        S.append(input())
    graph = [[] for i in range(N)]
    for i in range(N):
        a = S[i]
        for j in range(max(0, i - K), min(N, i+K + 1)):
            if a[j] == '1' and i != j:
                graph[i].append(j)
    p = minEdgeBFS(graph, N - 1, N)
    print(p)