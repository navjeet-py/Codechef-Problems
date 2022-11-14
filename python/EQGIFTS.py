from copy import copy
N = int(input())
prices = []
for i in range(N):
    prices.append(list(map(int, input().split())))
total = 0
for i in prices:
    total += sum(i)
poss = [0] * (total + 1)
poss[0] = 1
for i in range(N):
    p1, p2 = prices[i]
    change = []
    for j in range(total + 1):
        if poss[j] == 1:
            change.append(j)
    for j in change:
        poss[j] = 0
    for j in change:
        poss[j + p1] = 1
        poss[j + p2] = 1

haha = []
for i in range(total + 1):
    if poss[i] == 1:
        haha.append(i)
mn = float('inf')
for i in haha:
    mn = min(mn, abs(total - 2 * i))
print(mn)