N = int(input())
array = []
for i in range(N):
    array.append(int(input()))
haha = [1] * N
for i in range(N):
    for j in range(i + 1, N):
        if array[j] % array[i] == 0:
            haha[j] = max(haha[i] + 1, haha[j])
print(max(haha))
