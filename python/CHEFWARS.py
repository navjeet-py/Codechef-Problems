for _ in range(int(input())):
    H, P = map(int, input().split())
    mx = P
    while P > 0:
        P = P // 2
        mx += P
    print(1 if mx >= H else 0)
