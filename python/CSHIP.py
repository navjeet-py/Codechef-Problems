for _ in range(int(input())):
    N, K = map(int, input().split())
    array = list(map(int, input().split()))
    sm = 0
    for i in range(K):
        sm += array[i]
    mx = sm
    for i in range(K, N):
        sm += array[i]
        sm -= array[i - K]
        mx = max(sm, mx)
    print(mx)