for _ in range(int(input())):
    a, d, k, n, inc = map(int, input().split())
    for i in range(1, n):
        a += d
        if (i+1) % k == 0:
            d += inc
    print(a)