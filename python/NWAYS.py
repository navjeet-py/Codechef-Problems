factorial = [1]
mod = 10 ** 9 + 7
for i in range(1, 3000000):
    a = (factorial[-1] * i) % mod
    factorial.append(a)


def C(a, b):
    if b > a: return 0
    num = factorial[a]
    den = (factorial[b] * factorial[a - b]) % mod
    inverse = pow(den, mod - 2, mod)
    answer = (num * inverse) % mod
    return answer


def solve2(N, K):
    num = ((N + 1) * C(K + N + 1, K) - (K ** 2 + 3 * K + 2)) % mod
    num *= 2
    num = (num * N) % mod
    den = ((K + 1) * (K + 2)) % mod
    inverse = pow(den, mod - 2, mod)
    answer = (num * inverse) % mod
    return (answer + N) % mod


for i in range(int(input())):
    N, K = map(int, input().split())
    # print(C(N, K))
    print(solve2(N, K))