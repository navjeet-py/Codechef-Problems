N = int(input())
array = list(map(int, input().split()))
final = [1]
for i in range(1, N):
    final.insert(i - array[i], i + 1)
print(*final)