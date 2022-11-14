for _ in range(int(input())):
    N = int(input())
    array = list(map(int, input().split()))
    pre_sum = [array[0]]
    for i in range(1, N):
        pre_sum.append(pre_sum[-1] + array[i])

    Q = int(input())
    for i in range(Q):
        a, b = map(int, input().split())
        if a == 1:
            print(pre_sum[b-1])
        else:
            print(pre_sum[b-1] - pre_sum[a-2])