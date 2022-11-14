asks = [1]
for i in range(1, 20):
    asks.append(asks[-1] + 2 ** i)

for _ in range(int(input())):
    N = int(input())
    digits = ''
    print(1, 1)
    res = int(input())
    last = res
    digits = str(int(res - N) % 2) + digits
    for i in range(1, 20):
        print(1, asks[i])
        res = int(input())
        digits = str(int((((res - last) / 2 ** i) - N) / 2) % 2) + digits
        last = res

    print(2, int(digits, 2))
    res = int(input())
    if res == -1:
        break