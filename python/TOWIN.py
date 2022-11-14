for _ in range(int(input())):
    N = int(input())
    array = list(map(int, input().split()))
    first, second = 0,0
    if N == 1:
        first = array[0]
    elif N == 2:
        first = max(array)
        second = min(array)
    else:
        array.sort()
        array = array[-1::-1]
        first = array[0]
        second = array[1] + array[2]
        for i in range(3, N):
            if i % 2 == 1:
                first += array[i]
            else:
                second += array[i]
    if first > second:
        print('first')
    elif second > first:
        print('second')
    else:
        print('draw')