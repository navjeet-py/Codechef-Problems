from copy import copy
first, second = [3, 4, 5, 6, 7, 2, 1, 0], [4, 5, 6, 7, 3, 2, 1, 0]

def next(current):
    if current[1] == 0: return [first[first.index(current[0])+1], 4]
    else: return [current[0], second[second.index(current[1]) + 1]]

def getInitial():
    p,q = ['X']*8,[]
    for i in range(8): q.append(copy(p))
    q[3][4] = 'O'
    return q

for _ in range(int(input())):
    array, current = getInitial(), next([3,4])
    K = int(input())

    for i in range(K-1):
        array[current[0]][current[1]] = '.'
        try: current = next(current)
        except: current = [3,4]

    for i in range(8):
        for j in range(8):print(array[i][j],end='')
        print()

