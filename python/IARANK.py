import bisect

N = int(input())

wealths = [int(input())]
print(1)
for i in range(N - 1):
    a = int(input())
    idx = bisect.bisect(wealths, a)
    wealths.insert(idx, a)
    print(i - idx + 2)
