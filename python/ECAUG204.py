for _ in range(int(input())):
    N = int(input())
    array = list(map(int, input().split()))
    dic = {}
    poss = 'Yes'
    for i in array:
        if i in dic.keys():
            poss = 'No'
            break
        else:
            dic[i] = 1
    print(poss)