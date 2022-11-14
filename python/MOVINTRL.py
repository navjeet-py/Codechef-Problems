from copy import copy
def possible(array):
    for i in range(1, N):
        if array[i][0] <= array[i - 1][1]:
            return [False, i]
    return [True, 0]

def update(array, j):
    p = array[j]
    diff = p[1] - p[0] + 1
    array.pop(j)
    array.append([C + 1, C + 1])
    array.insert(0, [0,0])
    for i in range(1, N):
        if array[i][0] - array[i - 1][1] > diff:
            array.insert(i, [array[i-1][1] + 1, array[i-1][1] + diff ])
            array.pop(-1)
            array.pop(0)
            return [True, array]
    return [False, 0]

for _ in range(int(input())):
    C, N, K = map(int, input().split())
    main_array = []
    for i in range(N):
        main_array.append(list(map(int, input().split())))
    main_array.sort()
    if K == 0:
        if possible(main_array)[0]:
            print('Good')
        else:
            print('Bad')
    else:
        p = possible(main_array)
        if p[0]:
            print('Good')
        else:
            final = 'Bad'
            a = update(copy(main_array), p[1])
            b = update(copy(main_array), p[1] - 1)
            # print(a,b)
            if a[0] and possible(a[1])[0]:
                final = 'Good'
            elif b[0] and possible(b[1])[0]:
                final = 'Good'
            print(final)