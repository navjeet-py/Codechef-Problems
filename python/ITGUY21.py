def solve(N):
    if N == 1:
        print('0')
    elif N == 2:
        print('0')
        print('01')
    else:
        ans = '01'
        print('0')
        print('01')
        first = 0
        second = 1
        for i in range(N - 2):
            ans += str(first + second)
            print(ans)
            temp = first
            first = second
            second = temp + first


for _ in range(int(input())):
    N = int(input())
    solve(N)