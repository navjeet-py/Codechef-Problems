def power_2(n):
    if n % 2 == 1:
        return 0
    if n % 4 == 0:
        return 2
    return 1

def solve(interval):
    return (interval[2] - interval[1] + 1) * (interval[1] - interval[0] + 1)

for _ in range(int(input())):
    N = int(input())
    array = list(map(int, input().split()))
    final = [power_2(i) for i in array]
    total_sub = (N*(N - 1)) // 2 + N
    start = 0
    one_is_at = -1
    intervals = []
    for i in range(N):
        if final[i] == 2:
            if one_is_at != -1:
                intervals.append([start, one_is_at, i - 1])
            start = i + 1
            one_is_at = -1
        elif final[i] == 1:
            if one_is_at == -1:
                one_is_at = i
            else:
                intervals.append([start, one_is_at, i - 1])
                start = one_is_at + 1
                one_is_at = i
    if one_is_at != -1:
        intervals.append([start, one_is_at, N - 1])

    sm = 0
    for i in intervals:
        sm += solve(i)
    print(total_sub - sm)