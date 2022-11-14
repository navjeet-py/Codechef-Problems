from math import sqrt
def primeFactors(n):
    count = 0
    while n % 2 == 0:
        count += 1
        n = n / 2
    for i in range(3, int(sqrt(n)) + 1, 2):
        while n % i == 0:
            count += 1
            n = n / i

    if n > 2:
        count += 1
    return count

for _ in range(int(input())):
    X, K = map(int, input().split())
    if primeFactors(X) >= K:
        print(1)
    else:
        print(0)