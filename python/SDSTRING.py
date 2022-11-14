for _ in range(int(input())):
    S = input()
    ones = 0
    zero = 0
    for i in S:
        if i == '0': zero += 1
        else: ones += 1
    if (ones + zero ) % 2 == 1:
        print(-1)
    elif zero == 0:
        print(-1)
    elif ones == 0:
        print(-1)
    else:
        print(abs(zero - ones) // 2)