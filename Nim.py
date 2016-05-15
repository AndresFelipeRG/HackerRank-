n = int(input())

def nim_sum(stacks):
    res = 0
    for i in stacks:
        res = res ^i
    return res

for x in range(n):
    
    in_d = int(input())
    count = in_d
    current_player = 0
    lst = input().split()
    counter = 0
    stacks = []
    for j in lst:
        stacks.append(int(j))
  
    if nim_sum(stacks) == 0:
        print ("Second")
   
    if nim_sum(stacks) > 0:
        print ("First")
