for _ in range(int(input())):
    N, K = map(int, input().split())
    array = list(map(int, input().split()))
    poss = 0
    mn = 100000000000
    mnIdx = 0
    for i in array:
        if K % i == 0:
            if mn > K // i:
                mnIdx = i
                mn = K // i
            poss = 1
    if poss == 0:
        print(-1)
    else:
        print(mnIdx)