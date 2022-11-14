def solve(arr):
    N = len(arr)
    i = 0
    j = N - 1
    while (i < j):
        if arr[i] + arr[j] == 2000:
            return True
        elif arr[i] + arr[j] < 2000:
            i+=1
        else:
            j-=1
    return False

for _ in range(int(input())):
    N = int(input())
    array = list(map(int, input().split()))
    p = []
    for i in array:
        if i<=2000:
            p.append(i)
    p.sort()
    if solve(p):
        print('Accepted')
    else:
        print('Rejected')
