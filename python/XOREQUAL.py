mod = 10 ** 9 + 7
T = int(input())
for test_case in range(T):
    N = int(input())
    print(pow(2, N - 1, mod))