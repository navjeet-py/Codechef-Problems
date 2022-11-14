for _ in range(int(input())):
    C, R = map(int, input().split())
    p = (C - 1) // 9 + 1
    q = (R - 1) // 9 + 1
    if p >= q:
        print(1, q)
    else:
        print(0, p)
