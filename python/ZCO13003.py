N, K = map(int, input().split())
hardnesses = list(map(int, input().split()))

hardnesses.sort()

i, j = 0, N - 1
count = 0

while j >= i:
    if hardnesses[i] + hardnesses[j] >= K:
        j -= 1
        
    else:
        count += (j - i)
        i += 1

print(count)