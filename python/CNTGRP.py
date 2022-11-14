mod = 10 ** 9 + 7
from math import factorial
def create_dic(array):
    dic = {}
    for i in array:
        if i in dic:
            dic[i] += 1
        else:
            dic[i] = 1
    return dic

def C(n, r):
    if r > n:
        return 0
    elif r == n:
        return 1
    elif r == 0:
        return 1

    r = max(r, n - r)

    num = 1
    for i in range(r + 1, n + 1):
        num = (num * i) % mod
    den = 1
    for i in range(1, n - r + 1):
        den = (den * i) % mod
    tbm = pow(den, mod - 2, mod)

    num = (num * tbm) % mod
    return num


for _ in range(int(input())):
    N, M = map(int, input().split())
    array = list(map(int, input().split()))
    total = 0
    if M >= N - 1:
        dic = create_dic(array)
        # print(dic)
        if 1 in dic.keys():
            possible = True
            cnt = dic[1]
            search = 2
            total = 1
            while cnt < N - 1 and possible:
                if search in dic.keys():
                    total = (total * pow(dic[search - 1], dic[search], mod)) % mod
                    cnt += dic[search]
                    search += 1
                else:
                    possible = False
                    total = 0
        else:
            total = 0


    if total > 0:
        left = M  - N + 1
        pis = 0
        for value in dic.values():
            pis += ((value * (value - 1)) // 2)
        total = (total * C(pis, left)) % mod

    print(total)
