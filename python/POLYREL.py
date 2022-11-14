for _ in range(int(input())):
    N = int(input())
    coords = []
    for i in range(N):
        coords.append(list(map(int, input().split())))
    ans = N
    while N > 5:
        N = N // 2
        ans += N
    print(ans)