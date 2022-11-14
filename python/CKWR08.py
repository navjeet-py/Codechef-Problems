for _ in range(int(input())):
    N, K = map(int, input().split())
    array = list(map(int, input().split()))
    print(max(array) - min(array) + 2 * K)
