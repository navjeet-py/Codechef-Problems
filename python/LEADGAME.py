N = int(input())
A = 0
B = 0
mx = 0
mxBy = 1
for i in range(N):
    a, b = map(int, input().split())
    A += a
    B += b
    if abs(A - B) > mx:
        mx = abs(A - B)
        if A > B:
            mxBy = 1
        else:
            mxBy = 2
print(mxBy, mx)
