for _ in range(int(input())):
    N = int(input())
    array = list(map(int, input().split()))
    sm = 0
    for i in array:
        if i % 2 == 0:
            sm += i
    print(sm)