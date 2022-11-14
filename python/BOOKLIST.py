M = int(input())
array = list(map(int, input().split()))
N = int(input())
borrowed = []
for i in range(N):
    a = int(input())
    p = array.pop(a - 1)
    borrowed.append(p)
for i in borrowed:
    print(i)