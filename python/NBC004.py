mod = 1000000007
for _ in range(int(input())):
    N = int(input())
    print(((N-1)**2 + N**3) % mod)