for _ in range(int(input())):
    X, A, B = map(int, input().split())
    print(((100 - X) * B + A) * 10)