from copy import copy
a = list(map(int, input().split()))
N, K, first, second = a[0], a[1], copy(a[2: a[0] + 2]), copy(a[a[0] + 2:])
first.sort()
second.sort()
a = a[2:]
a.sort()
breaker = a[N]
p = 0

for i in first:
    if i > breaker:
        p += 1

if min(p, N - p) <= K:
    print(a[N-1] + a[-1])
else:
    print(a[-1] + min(first[N- K - 1], second[N - K - 1]))