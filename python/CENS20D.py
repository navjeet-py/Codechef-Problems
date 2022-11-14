for _ in range(int(input())):
    N = int(input())
    array = list(map(int, input().split()))
    cnt = 0
    for i in range(N):
        for j in range(i + 1 , N):
            if array[i] & array[j] == array[i]:
                cnt += 1
    print(cnt)