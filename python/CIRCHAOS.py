from math import gcd
import math


def printDivisors(n, N):
    d = []
    i = 1
    while i <= math.sqrt(n):

        if (n % i == 0):

            if (n / i == i):
                d.append(i)
            else:
                # Otherwise print both
                d.append(i)
                d.append(n // i)

        i = i + 1
    d.sort()
    d = d[-1::-1]
    for i in d:
        if i <= N:
            return i




for _ in range(int(input())):
    N, M = map(int, input().split())
    p = list(map(int, input().split()))
    g = p[0]
    for i in range(1, M):
        g = gcd(g, p[i])
    if g > N:
        if g % N == 0:
            print(0)
        else:
            k = printDivisors(g, N)
            print(N - k)
    elif N == 1:
        print(0)
    else:
        print(N - g)