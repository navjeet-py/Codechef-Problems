# cook your dish here
for _ in range(int(input())):
    C, D, L = map(int, input().split())
    if (L % 4 != 0):
        print('no')
        continue
    
    cnt = L // 4
    mx = C + D
    mn = D + max(0, C - 2 * D)
    if (mn <= cnt <= mx):
        print('yes')
    else:
        print('no')