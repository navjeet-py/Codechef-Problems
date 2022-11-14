for _ in range(int(input())):
    N, x = map(int, input().split())
    array = list(map(int, input().split()))
    array.sort()
    array = array[-1::-1]
    dynamic, static = [], []
    for i in array:
        if 2*i >= x:
            dynamic.append(i)
        else:
            static.append(i)
            
    l = len(dynamic) - 1
    count = 0
    while l >= 0:
        if x >= dynamic[l]:
            x = 2*dynamic[l]
            l -= 1
            count += 1
        elif x >= dynamic[0]:
            count += (l+1)
            l = -1
            break
        else:
            x = 2*x
            count += 1
    count += (len(static))
    print(count)