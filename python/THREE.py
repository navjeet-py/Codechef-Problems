for _ in range(int(input())):
    S = input()
    N = len(S)
    dic = {}
    for i in S:
        if i in dic.keys():
            dic[i] += 1
        else:
            dic[i] = 1
    p = list(dic.values())
    p.sort()
    cnt = 0
    for i in p:
        cnt += (i // 2)
    print(min(cnt, N // 3))
