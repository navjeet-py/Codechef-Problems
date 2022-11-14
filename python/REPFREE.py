biggest = 987654321
def check(n):
    dic = {}
    if '0' in str(n):return False
    for i in str(n):
        if i in dic.keys():
            return False
        else:
            dic[i] = 1
    return True

N = int(input())
if N >= biggest:
    print(0)
else:
    p = N + 1
    while not check(p): p+=1
    print(p)