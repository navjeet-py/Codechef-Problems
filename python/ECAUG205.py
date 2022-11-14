def possible(page):
    if page == 0:
        return True
    total = 0
    for i in array:
        total += (i // page)
    if total >= K:
        return True
    else:
        return False


for _ in range(int(input())):
    N, K = map(int, input().split())
    array = list(map(int, input().split()))
    l = 0
    r = 10 ** 9
    while l < r:
        mid = (l + r) // 2
        if possible(mid):
            l = mid + 1
        else:
            r = mid - 1
    if possible(l):
        print(l)
    else:
        print(l - 1)
