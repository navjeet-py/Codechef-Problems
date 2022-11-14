N, H = map(int, input().split())
box_counts = list(map(int, input().split()))
commands = list(map(int, input().split()))

C = len(commands)

hold = 0
pos = 0

for i in range(len(commands) - 1):
    com = commands[i]
    if com == 1:
        pos = max(0, pos - 1)
    elif com == 2:
        pos = min(N - 1, pos + 1)
    elif com == 3:
        if hold == 0:
            if box_counts[pos] >= 1:
                box_counts[pos] -= 1
                hold = 1
    elif com == 4:
        if hold == 1:
            if box_counts[pos] <= H - 1:
                box_counts[pos] += 1
                hold = 0
print(*box_counts)