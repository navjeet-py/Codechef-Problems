for _ in range(int(input())):
    print("Test case :", _ + 1)
    N = list(input().strip())
    q = int(input())
    for query in range(q):
        p = list(input().split())
        ans = 0
        if p[1] == '*':
            for i in N:
                ans += (int(i) * int(p[0]))
            print(ans)
        elif p[1] == '/':
            ans = 0
            if p[0] == '0':
                print("INVALID INPUT.'0' IS EVIL")
            else:
                for i in N:
                    ans += (int(i) // int(p[0]))
                print(ans)
        else:
            ans = 0
            for i in range(len(N)):
                N[i] = str(int(N[i]) + int(p[0]))
                ans += int(N[i])
            print(ans)