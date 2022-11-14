def dfs(u, cc):
    ccnum[u] = cc
    for i in graph[u]:
        if ccnum[i] == -1:
            dfs(i, cc)
    return

N = int(input())
risk = list(map(int, input().split()))
K = int(input())
graph = [[] for i in range(N)]
for i in range(K):
    u, v = map(int, input().split())
    graph[u-1].append(v-1)
    graph[v-1].append(u-1)
ccnum = [-1] * N
c = 1
for pp in range(N):
    if ccnum[pp] == -1:
        dfs(pp, c)
        c += 1
# print(ccnum)
dic = {}
for i in range(N):

    if ccnum[i] in dic.keys():
        dic[ccnum[i]].append(i)
    else:
        dic[ccnum[i]] = [i]

ans = 1

for value in dic.values():
    t = []
    for i in value:
        t.append(risk[i])
    mn = min(t)
    ans = ans * t.count(mn)
print(ans)