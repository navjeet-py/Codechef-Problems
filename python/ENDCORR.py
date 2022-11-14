import heapq
N, M = map(int, input().split())
array = [-int(input())]
heapq.heapify(array)
for i in range(N + M - 1):
    a = int(input())
    if a == -1:
        mx = heapq.heappop(array)
        print(-mx)
    else:
        heapq.heappush(array, -a)