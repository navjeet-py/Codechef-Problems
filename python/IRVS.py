# from math import sqrt

prime = [True] * (1000001)
for i in range(2, 100000):
    if prime[i]:
        k = 2
        while i * k < 1000000:
            prime[i * k] = False
            k += 1

# print(prime[:20])
for _ in range(int(input())):
    N = int(input())
    sm = 0
    for i in range(2, N+ 1):
        if prime[i]:
            sm = (sm + i) % 10
    print(sm)