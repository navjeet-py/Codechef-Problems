import heapq

for _ in range(int(input())):
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    dic = {}
    for i in range(N):
        if B[i] in dic: dic[B[i]].append(A[i])
        else: dic[B[i]] = [A[i]]
    li = []
    mx = 0
    sm = 0
    cnt = 0

    idx = 0
    while True:
        if idx in dic:
            for i in dic[idx]:
                heapq.heappush(li, -i)
        idx += 1
        if len(li) == 0:
            break
        eff = -heapq.heappop(li)
        sm += eff
        cnt += 1
        mx = max(mx, sm/cnt)
    print(mx)





