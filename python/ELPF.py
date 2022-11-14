for _ in range(int(input())):
    N, M = map(int, input().split())
    p = [10]*N
    for m in range(M):
        i, j, k = map(int, input().split())
        for pp in range(i - 1, j):
            p[pp] *= k

    print(sum(p) // N)