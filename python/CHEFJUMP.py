for _ in range(int(input())):

    hr, mn = map(int, input().split(':'))
    hr %= 12
    mn //= 5
    mn_deg = mn * 30
    hr_deg = hr * 30 + mn * 2.5
    ans = abs(mn_deg - hr_deg)
    ans = min(ans, 360-ans)
    if ans == int(ans):
        
        print(int(ans), 'degree')
    else:
        print(ans, 'degree')