from bisect import bisect

for _ in range(int(input())):
    N = int(input())
    array = list(map(int, input().split()))
    top = [array[0]]
    for i in array[1:]:
        p = bisect(top, i)
        if p == len(top):
            top.append(i)
        else:
            top[p] = i

    print(len(top), *top)
