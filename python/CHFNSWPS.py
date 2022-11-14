from copy import copy

def count_dictionary(array):
    res = {}
    for i in array:
        if i in res.keys():
            res[i] += 1
        else:
            res[i] = 1
    return res

def find_diff(A, B):
    diff_array = [ [], [] ]
    for i in A.keys():
        if ((A[i]-B[i]) % 2 != 0):
            return False
        else:
            if A[i] > B[i]:
                diff_array[0].append([i, (A[i] - B[i])//2])
            elif B[i] > A[i]:
                diff_array[1].append([i, (B[i] - A[i])//2])
    diff_array[0].sort()
    diff_array[1].sort()
    final = [ [], [] ]
    for i in diff_array[0]:
        for j in range(i[1]):
            final[0].append(copy(i[0]))
    for i in diff_array[1]:
        for j in range(i[1]):
            final[1].append(copy(i[0]))
    return final

for _ in range(int(input())):
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    mn = min(min(A), min(B))
    A = count_dictionary(A)
    B = count_dictionary(B)
    total_keys = list(set(list(A.keys()) + list(B.keys())))
    for i in total_keys:
        if i not in A.keys():
            A[i] = 0
        if i not in B.keys():
            B[i] = 0

    alpha = find_diff(A,B)


    if alpha == False:
        print(-1)
    else:
        A = alpha[0]
        B = alpha[1][-1::-1]

        total = 0
        l = len(A)
        for i in range(l):
            if min(A[i], B[i]) == mn:
                total += mn
            else:
                total += min(2*mn, min(A[i], B[i]))
        print(total)