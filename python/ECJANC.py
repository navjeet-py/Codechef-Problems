for _ in range(int(input())):
    X,Y,Z,T = map(int, input().split())
    p = X*Y+Z
    balloons = Y*(T//p)
    left = T % p
    if left >= X * Y:
        balloons += Y
    else:
        balloons += (left // X)
    print(balloons)