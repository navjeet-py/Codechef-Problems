N = int(input())
array = list(map(int, input().split()))
if N <= 2:
    print(0)
else:
    cnt = [array[0], array[1], array[2]]
    for i in range(3,N):
        cnt.append(min(cnt[i - 1], cnt[i - 2], cnt[i - 3]) + array[i])
    print(sum(array) - min(cnt[N - 1], cnt[N - 2], cnt[N - 3]))
