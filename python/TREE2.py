for _ in range(int(input())):
    N = int(input())
    array = list(map(int, input().split()))
    dic = {}
    for i in array:
        if i!= 0:
            if i not in dic.keys():
                dic[i] = 1
    print(len(dic.keys()))