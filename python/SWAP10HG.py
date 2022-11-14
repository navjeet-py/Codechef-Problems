

for _ in range(int(input())):
    N = int(input())
    S = input()
    T = input()
    a, b = 0, 0
    possible = True
    for i in range(N):
        if S[i] == '0':
            a += 1
        if T[i] == '0':
            b += 1
        if (a > b):
            possible = False
    if possible and a == b:
        print("Yes")
    else:
        print("No")