C, F = map(int, input().split())
graph = [[float('inf') for i in range(C)] for j in range(C)]
for i in range(F):
    u, v, p = map(int, input().split())
    graph[u - 1][v - 1] = p
    graph[v - 1][u - 1] = p

for i in range(C):
    graph[i][i] = 0

for k in range(C):
    for i in range(C):
        for j in range(C):
            graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j])

mx = graph[0][0]
for i in graph:
    mx = max(mx, max(i))
print(mx)