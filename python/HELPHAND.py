def isPrime(n):
    if (n <= 1):
        return False
    if (n <= 3):
        return True
    if (n % 2 == 0 or n % 3 == 0):
        return False
    i = 5
    while (i * i <= n):
        if (n % i == 0 or n % (i + 2) == 0):
            return False
        i = i + 6
    return True

final = [0, 0, 1, 2, 3, 5]
for i in range(6,10**6+5):
    if isPrime(i):
        final.append(final[-1]+2)
    else:
        final.append(final[-1]+1)

for _ in range(int(input())):
    N = int(input())
    print(final[N])