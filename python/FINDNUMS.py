S, P, K = map(int, input().split())
array = []
possible = False
if K == 1:
    if P == S:
        array = [P]
        possible = True
elif K == 2:
    for i in range(1000):
        for j in range(1000):
            if i * j == P and i + j == S:
                array = [i,j]
                possible = True
else:
    factors = []
    for i in range(1, P+1):
        if P % i == 0:
            factors.append(i)
    if K == 3:
        for i in factors:
            for j in factors:
                for k in factors:
                    if i + j + k == S and i * j * k == P:
                        array = [i,j,k]
                        possible = True
    elif K == 4:
        for i in factors:
            for j in factors:
                for k in factors:
                    for l in factors:
                        if i + j + k + l == S and i * j * k * l == P:
                            array = [i, j, k, l]
                            possible = True
if possible:
    print(*array)
else:
    print('NO')