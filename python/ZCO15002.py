N, K = map(int, input().split())
array = list(map(int, input().split()))
array.sort()
i = 0
j = 1
count = 0
while i < N-1 and j < N:
    if array[j] - array[i] >= K:
        count += (N - j)
        i += 1
    else:
        j += 1
print(count)