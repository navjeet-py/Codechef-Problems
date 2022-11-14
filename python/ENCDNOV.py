from copy import copy

for _ in range(int(input())):
    N  = int(input())
    array = list(map(int, input().split()))
    p = copy(array)
    p.sort()
    if p == array:
        print(0)
    else:

        start = 0
        for i in range(N):
            if p[i] != array[i]:
                start = i
                break
        end = N - 1
        for i in range(N- 1, -1, -1):
            if p[i] != array[i]:
                end = i
                break
        print(end - start + 1)