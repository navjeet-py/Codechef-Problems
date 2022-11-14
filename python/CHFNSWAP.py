from math import sqrt

for _ in range(int(input())):
    N = int(input())
    if N % 4 == 3 or N % 4 == 0:
        ans = 0
        s = int((N / 2) * sqrt(2))
        # print('s', s)
        half = (N * (N + 1)) // 4
        for i in range(-2, 2):
            a = s + i
            haha = (a * (a + 1)) // 2
            if haha == half:
                ans += ((a * (a -  1)) // 2)
                pp = N - a 
                ans += ((pp * (pp -  1)) // 2)
            elif haha < half and half - haha <= N - 1:
                diff = half - haha
                ans += min(diff, N - diff, a, N - a)
        print(ans)
    else:
        print(0)