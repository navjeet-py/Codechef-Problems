for _ in range(int(input())):
    N = int(input())
    array = list(map(int, input().split()))
    # N = len(array)
    pairs = []
    pair_first = -1
    for i in range(1, N):
        if array[i-1] == 0 and array[i] == 1:
            pairs.append(i - pair_first)
        elif array[i-1] == 1 and array[i] == 0:
            pair_first = i
    if len(pairs) > 0:


        a = max(pairs)
        if pairs.count(a) > 1:
            print('No')
        else:
            if a % 2 == 0:
                print('No')
            else:
                if len(pairs) == 1:
                    print('Yes')
                else:
                    pairs.sort()
                    if pairs[-2] > (a // 2):
                        print('No')
                    else:
                        print('Yes')
    else:
        print('No')