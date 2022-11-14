N = int(input())
array = []
for i in range(N):
    a = input()
    a = a.replace('.', '')
    a = a.replace(',', '')
    a = a.replace(':', '')
    a = a.replace("'", '')
    a = a.replace(';', '')
    array.append(list(a.split()))

for i in range(N - 1, -1, -1):
    p = array[i][-1::-1]
    print(*p)