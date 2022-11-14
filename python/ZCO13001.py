N = int(input())
array = list(map(int, input().split()))
array.sort()

sum = 0
for i in range(N):
    sum += ((2 * i - N + 1) * array[i])
print(sum)
