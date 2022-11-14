

for _ in range(int(input())):
    N = int(input())
    X = {}
    Y = {}
    for i in range(4 * N - 1):
        x, y = map(int, input().split())
        if x in X.keys():
            X[x] += 1
        else:
            X[x] = 1
        if y in Y.keys():
            Y[y] += 1
        else:
            Y[y] = 1
    odd = [0,0]
    
    for i in X.keys():
        if X[i] % 2 != 0:
            odd[0] = i
    for i in Y.keys():
        if Y[i] % 2 != 0:
            odd[1] = i
    print(*odd)
    