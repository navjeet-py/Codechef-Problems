N = int(input())
events = []
for i in range(N):
    a, b = map(int, input().split())
    events.append([a+b, -a])
events.sort()
for i in range(N):
    events[i][1] *= -1
count = 1
last = 0
for i in range(1, N):
    if events[i][1] > events[last][0]:
        count += 1
        last = i
print(count)
