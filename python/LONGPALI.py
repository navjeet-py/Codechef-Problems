def is_palin(string):
    if string[-1] == string[0]:
        if string[-1::-1] == string:
            return True
    return False


N = int(input())
S = input()

if N == 1:
    print(S)
else:
    length = N
    while length > 0:
        for start in range(0, N - length + 1):
            if is_palin(S[start:start+length]):
                print(length)
                print(S[start:start+length])
                length = -1
                break
        length -= 1
