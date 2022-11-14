from copy import copy
import queue
def is_palin(array):
    if array[-1::-1] == array:
        return True
    return False


def minEdgeBFS(edges, u, v, n):
    visited = [0] * n
    distance = [0] * n

    Q = queue.Queue()
    distance[u] = 0

    Q.put(u)
    visited[u] = True
    while (not Q.empty()):
        x = Q.get()

        for i in range(len(edges[x])):
            if (visited[edges[x][i]]):
                continue
            distance[edges[x][i]] = distance[x] + 1
            Q.put(edges[x][i])
            visited[edges[x][i]] = 1
    return distance[v]


N = int(input())
array = list(map(int, input().split()))

palin = []
for i in range(N+1):
    palin.append(copy([]))

for i in range(N):
    for j in range(i+1,N+1):
        if is_palin(array[i:j]):
            palin[i].append(j)
answer = minEdgeBFS(palin, 0, N, N+1)
print(answer)
