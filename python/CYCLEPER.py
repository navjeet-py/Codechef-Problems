N = int(input())
array = list(map(int, input().split()))
visited = [0] * N
toPrint = []
for i in range(N):
    if visited[i] == 0:
        t = []
        visited[i] = 1
        a = i + 1
        t.append(a)
        p = array[i]
        visited[p - 1] = 1
        while p != a:
            t.append(p)
            p = array[p - 1]
            visited[p - 1] = 1
        t.append(a)
        toPrint.append(t)
print(len(toPrint))
for i in toPrint:
    print(*i)

