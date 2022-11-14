x = {}
alpha = 'abcdefghijklmnopqrstuvwxyz'
for i in range(26):
    x[alpha[i]] = alpha[25-i]

for _ in range(int(input())):
    N = int(input())
    S = list(input().strip())
    for i in range(N // 2):
        a = i * 2
        b = a + 1
        S[a], S[b] = S[b], S[a]
    
    for i in range(N):
        S[i] = x[S[i]]
    
    print(''.join(S))