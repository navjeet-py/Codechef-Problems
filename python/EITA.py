for _ in range(int(input())):
    d, x, y, z = map(int, input().split())
    print(max(x * 7, y * d + z * (7 - d)))
