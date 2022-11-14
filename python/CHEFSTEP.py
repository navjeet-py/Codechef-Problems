for _ in range(int(input())):
    N, K = map(int, input().split())
    atr = ''
    array = list(map(int, input().split()))
    for i in range(N):
        p = array[i]

        if p % K == 0:
            atr+='1'
        else:
            atr+='0'
    print(atr)