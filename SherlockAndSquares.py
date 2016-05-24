import math
num = int(input().strip())

for i in range(num):
    n = [int(a) for a in input().split()]
    count = 0
    inp = n[0]
    out = n[1]
    while out>= inp:
        res =math.sqrt(inp)
        if ((res - math.floor(res)) == 0):
            count +=1
            inp = res**2 + res + res +1
            continue
        inp +=1
            
    print(count)
            
