for _ in range(int(input())):
    p = list(input().split())
    a = p[0]
    if a[-1].lower() in 'auioe':
        print('Case #'+str(_+1) + ": "+a+" is ruled by a queen.")
    elif a[-1].lower() == 'y':
        print('Case #'+str(_+1) + ": "+a+" is ruled by nobody.")
    else:
        print('Case #'+str(_+1) + ": "+a+" is ruled by a king.")
