n = int(input())
def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

def nim_sum(stacks):
    res = 0
    for i in stacks:
        res = res ^(i)
    return res



for x in range(n):
    
    in_d = int(input())
    count = in_d
    current_player = 0
    lst = input().split()
    counter = 0
    stacks = []
    for j in lst:
        num = len(prime_factors(int(j)))
        
        stacks.append(num)
       
    if nim_sum(stacks) == 0:
        print ("2")
    if nim_sum(stacks) > 0 : 
        print("1")
