from math import gcd

for _ in range(int(input())):
    M, N = map(int, input().split())
    l = (M * N )  // gcd(M ,N)
    print(l // M + l // N - 2)