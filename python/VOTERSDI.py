lengths = list(map(int, input().split()))
array = []

for i in range(sum(lengths)):
    array.append(int(input()))
dic = {}
for i in array:
    if i in dic.keys():
        dic[i] += 1
    else:
        dic[i] = 1
array = []
for key, value in dic.items():
    if value >= 2:
        array.append(key)
array.sort()
print(len(array))
for i in array:
    print(i)