mod = 998244353
N = int(input())
den = 1
for i in range(1, N * 2, 2):
    den = (den * i) % mod

num = 0
for i in range(1, 2 * N, 2):
    num += ((pow(i, mod - 2, mod) * den) % mod)
num *= 2
num = num * pow(den, mod - 2, mod)
num %= mod
print(num)