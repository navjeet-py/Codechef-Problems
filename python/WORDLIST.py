N = int(input())
array = []
for i in range(N):
    a = input()
    a = a.replace(';', '')
    a = a.replace("'", '')
    a = a.replace('.', '')
    a = a.replace(',', '')
    a = a.replace(':', '')
    a = a.lower()
    array += (list(a.split()))
array = list(set(array))
array.sort()
print(len(array))
for i in array:
    print(i)