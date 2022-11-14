N = int(input())
for _ in range(N):
    a = input()
    i = 0
    pwd = ''
    while i < len(a):
        p = a[i]
        if p != '1':
            pwd += str(int(p) - 2)
            i += 1
        else:
            pwd += str(int(a[i:i+2]) - 2)
            i += 2

    print(pwd)