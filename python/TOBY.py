for _ in range(int(input())):
    N = int(input())
    S = input()
    u = S.count('U')
    d = S.count('D')
    l = S.count('L')
    r = S.count('R')
    print((min(u, d) + min(l, r)) * 2)