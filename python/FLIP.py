def solve(array):
    if len(array) == 0:
        return 0
    elif len(array) == 1:
        if array[0] == 0:
            return 1
        else:
            return 0
    res = 0
    for i in range(1, len(array)):
        if array[i] == 1 and array[i - 1] == 0:
            res += 1
    if array[-1] == 0:
        res += 1
    return res


for _ in range(int(input())):
    A = input()
    B = input()
    N = len(A)
    final = []
    for i in range(N):
        if A[i] == B[i]:
            final.append(1)
        else:
            final.append(0)

    odd = []
    even = []
    for i in range(0, N, 2):
        even.append(final[i])
    for i in range(1, N, 2):
        odd.append(final[i])
    cnt = solve(even) + solve(odd)
    print(cnt)
