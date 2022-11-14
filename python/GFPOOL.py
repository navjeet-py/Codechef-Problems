primes = [2, 3, 5, 7, 11, 13]

for _ in range(int(input())):
    N = int(input())
    array = list(map(int, input().split()))
    prime_aimon = 0
    if 11 in array: prime_aimon += 1
    if 13 in array: prime_aimon += 1
    prime_mia = 0
    if 2 in array: prime_mia += 1
    if 3 in array: prime_mia += 1
    if 5 in array: prime_mia += 1
    if 7 in array: prime_mia += 1
    if 8 not in array:
        print('Impossible')
        
    elif prime_aimon <= prime_mia:
        print('Aimon')
    else:
        print('Mia Malkova')
