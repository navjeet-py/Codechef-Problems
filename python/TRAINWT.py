for _ in range(int(input())):
    N = int(input())
    array = list(map(int, input().split()))
    sm = sum(array)
    Q = int(input())
    for i in range(Q):
        S, E, W = map(int, input().split())
        sm += ((E - S + 1) * W)
    print(sm)
