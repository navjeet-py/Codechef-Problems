def create_dic(string):
    dic = {}
    for i in string:
        if i in dic.keys():
            dic[i] += 1
        else:
            dic[i] = 1
    return dic

alphabets = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

for _ in range(int(input())):
    S = input()
    P = input()

    S_dic = create_dic(S)
    P_dic = create_dic(P)

    for i in P_dic.keys():
        S_dic[i] -= P_dic[i]

    first = P[0]
    second = ''
    for i in range(1, len(P)):
        if P[i] != first:
            second = P[i]
            break
    if second == '':
        second = first

    answer = ''

    for i in alphabets:
        if i == first:
            if i in S_dic:
                if second > first:
                    answer += (i * S_dic[i])
                    answer += P
                else:
                    answer += P
                    answer += (i * S_dic[i])
            else:
                answer += P
        else:
            if i in S_dic:
                answer = answer + (i * S_dic[i])
    print(answer)