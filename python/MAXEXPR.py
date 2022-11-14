import math
for _ in range(int(input())):
    N = int(input())
    K = list(map(float, input().split()))
    C = list(map(float, input().split()))

    kInverse = 0
    kc = 0

    for i in range(N):
        kc += (K[i] * C[i])
        kInverse += (1 / K[i])

    F_square = kc * kInverse

    if F_square < 0:
        print(-1)
    else:
        alpha = kc / kInverse
        X = []
        for i in range(N):
            X.append((alpha / (K[i] * K[i])) - C[i] )
        print(math.sqrt(F_square), end=' ')
        print(*X)
