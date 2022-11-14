for _ in range(int(input())):
    X, Y = map(int, input().split())
    alpha = []
    m = 1
    while m * X <= Y:
        alpha.append(m * X)
        m = 2 * m + 1


    cnt = 0

    for i in range(len(alpha) - 1, -1, -1):
        if (alpha[i] <= Y):
            Y -= alpha[i]
            cnt += (i + 2)

    cnt -= 1
    if Y != 0:
        print(-1)
    else:
        print(cnt)