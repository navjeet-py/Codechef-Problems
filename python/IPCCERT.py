N, M, K = map(int , input().split())
cnt  = 0
for i in range(N):
    arr = list(map(int, input().split()))
    sm = sum(arr) - arr[-1]
    if arr[-1] <= 10 and sm >= M:
        cnt += 1
print(cnt)