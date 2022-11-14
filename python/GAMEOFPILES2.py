def answer(arr):
    ones = arr.count(1)
    sm = sum(arr)
        
        
    if ones == 0:
        if sm % 2 == 0:
            return "CHEFINA"
        return "CHEF"
    
    if ones > 1:
        K = sm - N
        if K % 2 == 0:
            return "CHEFINA"
        return "CHEF"
    
    if len(arr) % 2 == 0:
        if sm % 2 == 0:
            return "CHEFINA"
        else:
            return "CHEF"
        
    two = arr.count(2)
    if (two == 0):
        if sm % 2 == 0:
            return "CHEFINA"
        if sm % 2 == 1:
            return "CHEF"
    
    if N % 2 == 1:
        return "CHEF"

    if sm % 2 == 0:
        return "CHEFINA"

    return "CHEF"
        
    
    

for _ in range(int(input())):
    N = int(input())
    A = list(map(int, input().split()))
    
    print(answer(A))