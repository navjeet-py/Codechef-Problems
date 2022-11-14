for _ in range(int(input())):
    N = int(input())
    array = list(map(int, input().split()))
    dic = {}
    poss = True
    for i in array:
        if i in dic.keys():
            poss = False
            break
        else:
            dic[i] = 1
    if poss:
        print('prekrasnyy')
    else:
        print('ne krasivo')