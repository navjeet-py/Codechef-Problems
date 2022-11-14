def create_dic(string):
    dic = {}
    for i in string:
        if i in dic.keys():
            dic[i] += 1
        else:
            dic[i] = 1
    return dic

for _ in range(int(input())):
    N = int(input())
    S = input()
    dic = create_dic(S)
    po = 'YES'
    for i in dic.values():
        if i % 2 != 0:
            po = 'NO'
    print(po)
