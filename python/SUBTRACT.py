N, K = map(int, input().split())
while(K > 0):
    if N % 10 == 0: N //= 10
    else: N -= 1
    K-=1
print(N)