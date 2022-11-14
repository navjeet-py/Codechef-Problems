for _ in range(int(input())):
    N = int(input())
    matrix = []
    for i in range(N):
        matrix.append(list(map(int, input().split())))
    array = matrix[0]
    reversed = False
    ans = 0
    for i in range(N-1, 0, -1):
        isFine = (array[i] == i + 1)
        if isFine == reversed:
            ans += 1
            reversed = not reversed

    print(ans)