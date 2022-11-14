N, X, Y = map(int, input().split())
start, end = [], []

for i in range(N):
    s, e = map(int, input().split())
    start.append([s, i])
    end.append([e, i])

V = list(map(int, input().split()))
W = list(map(int, input().split()))

# TOOK ALL INPUT================================

start.sort()
end.sort()
V.sort()
W.sort()

first = [-1]*N
i, j = N - 1, X - 1
while i >= 0 and j >= 0:
    if V[j] <= start[i][0]:
        first[start[i][1]] = j
        i -= 1
    else:
        j -= 1

second = [-1]*N
i, j = 0, 0
while i < N and j < Y:
    if W[j] >= end[i][0]:
        second[end[i][1]] = j
        i += 1
    else:
        j += 1

mx = 9999999999
for i in range(N):
    a = first[i]
    b = second[i]
    if min(a, b) != -1:
        mx = min(mx, W[b] - V[a] + 1)
print(mx)