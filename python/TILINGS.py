N = int(input())
f = [0, 1, 2]
g = [0, 1, 2]
for i in range(N):
    g.append((g[-1] + f[-1]) % 10000)
    f.append((f[-1] + f[-2] + 2 * g[-3]) % 10000)
print(f[N])