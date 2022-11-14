N = int(input())
array = []
for i in range(N):
    array.append(int(input()))
dic = {}
for i in array:
    if i in dic.keys():
        dic[i] += 1
    else:
        dic[i] = 1
count = 0
for i in range(N):
    for j in range(i + 1, N):
        a = (array[i] + array[j])
        if a % 2 == 0:
            p = a // 2
            if p in dic.keys():
                count += dic[p]
                dic[p] = 0
print(count)
