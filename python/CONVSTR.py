alpha = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
alphabets = {}
for i in range(26):
    alphabets[alpha[i]] = i

def partition(string):
    result = {}
    for i in alpha:
        result[i] = []
    for i in range(N):
        result[string[i]].append(i)
    return result
def checkPossibility(A, B, partition_a, partition_b):
    for i in range(N):
        if (alphabets[A[i]] < alphabets[B[i]]):
            return 0
    for i in alpha:
        if (len(partition_a[i]) == 0 and len(partition_b[i]) > 0):
            return 0
    return 1



for _ in range(int(input())):
    N = int(input())
    error = 0
    A = input()
    B = input()
    partition_a = partition(A)
    partition_b = partition(B)
    if checkPossibility(A, B,  partition_a, partition_b) == 0:
        print(-1)
    else:
        k = 0
        final = []
        for i in range(25,-1,-1):
            current_b = partition_b[alpha[i]]
            changes = []
            for j in current_b:
                if A[j] != alpha[i]:
                    changes.append(j)


            if len(changes) > 0:
                p = partition_a[alpha[i]][0]
                changes.append(p)
                final.append(changes)

        print(len(final))
        for i in final:
            print(len(i), *i)