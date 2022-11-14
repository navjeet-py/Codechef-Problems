def makeN(string, N):
    return ('0' * (N - len(string))) + string
def solve_one(array, binary, N):
    mns = [0, 0, 0]
    for pp in range(N):
        if binary[pp] == '1':
            for j in range(3):
                mns[j] = max(array[pp][j], mns[j])

    return mns


def solve(array, N):
    ans = 0
    for i in range(2 ** N):
        p = makeN(bin(i)[2:], N)
        mns = solve_one(array, p, N)
        # print(mns, p)
        if sum(mns) <= 10000:
            ans = max(ans, p.count('1'))

    return ans


for _ in range(int(input())):
    N = int(input())
    array = []
    for i in range(N):
        array.append(list(map(int, input().split())))
    ans = solve(array, N)
    print('Case #' + str(_+1) + ':',ans)