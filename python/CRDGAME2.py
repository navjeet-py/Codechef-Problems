mod = 10 ** 9 + 7
def C(n, r):
    if r > n:
        return 0
    elif r == n:
        return 1
    elif r == 0:
        return 1

    r = max(r, n - r)

    num = 1
    for i in range(r + 1, n + 1):
        num = (num * i) % mod
    den = 1
    for i in range(1, n - r + 1):
        den = (den * i) % mod
    tbm = pow(den, mod - 2, mod)

    num = (num * tbm) % mod
    return num

for _ in range(int(input())):
    N = int(input())
    array = list(map(int, input().split()))
    mx = max(array)
    cnt = array.count(mx)
    if cnt % 2 == 1:
        print(pow(2, N, mod))
    else:
        a = pow(2, N, mod)
        b = (pow(2, N - cnt, mod) * C(cnt, cnt // 2)) % mod

        print((a - b) % mod)