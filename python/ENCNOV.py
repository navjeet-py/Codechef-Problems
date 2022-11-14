for _ in range(int(input())):
    N, L, R = map(int, input().split())
    mn = 2 ** L - 1 + (N - L)
    mx = 2 ** R - 1 + (N - R) * (2 ** (R - 1))
    print(mn, mx)
