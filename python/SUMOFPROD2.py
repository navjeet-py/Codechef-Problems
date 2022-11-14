def fact(x, mod):
    ans = 1
    for i in range(1, x + 1):
        ans *= i
        ans %= mod
    return ans

def solve2(a, b, mod):
    ans = fact(b, mod) * a
    ans %= mod
    for i in range(1, a + 2):
        if i == 2:
            continue
        else:
            ans *= (b + i)
            ans %= mod
    return ans % mod


for _ in range(int(input())):
    N = int(input())
    A = list(map(int, input().split()))
    a = A.count(1)
    b = N - a
    print(solve2(a, b, 998244353))