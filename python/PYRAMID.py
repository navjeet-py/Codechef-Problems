M = int(input())
array = []
for i in range(M):
    a, b = map(int, input().split())
    array.append(min(a, b))
array.sort()
in_search_of = 1
cnt = 0
for i in range(M):
    if array[i] >= in_search_of :
        cnt += 1
        in_search_of += 1
print(cnt)