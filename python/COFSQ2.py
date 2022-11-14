bread, cheese = map(int, input().split())
#2a + 2b = bread
#2a + b = cheese
if bread - cheese >= 0:
    b = bread - cheese
    if cheese - b >= 0 and (cheese - b) % 2 == 0:
        a = (cheese - b) // 2
        print(a,b)
        print('Rs.', a * 220 +  b * 120)
    else:
        print(-1)
else:
    print(-1)