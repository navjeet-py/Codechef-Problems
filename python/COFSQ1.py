array = list(input().split())
final = []
for i in range(len(array)):
    if array[i][0] in 'aeiou':
        haha = array[i] + 'd' + 'u' * (i + 1)
    else:
        haha = array[i][1:] + array[i][0] + 'd' + 'u' * (i + 1)
    final.append(haha)
print(*final)