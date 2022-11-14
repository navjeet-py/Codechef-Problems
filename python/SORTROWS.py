N = int(input())
array = []
for i in range(N):
    a = (list(map(int, input().split())))
    a.pop(-1)
    array.append(a)
array.sort()
for i in array:
    print(*i)