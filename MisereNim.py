n = int(input())

def nim_sum(stacks):
    res = 0
    for i in stacks:
        res = res ^i
    return res


        
def num_stacks(stacks):
    num = 0
    for x in stacks:
        if x == 1:
            num = num +1
    
    return num
def num_stacks2(stacks):
    num = 0
    for x in stacks:
        if x > 1:
            num = num +1
    
    return num

for x in range(n):
    
    in_d = int(input())
    count = in_d
    current_player = 0
    lst = input().split()
    counter = 0
    stacks = []
    for j in lst:
        stacks.append(int(j))
  
    if nim_sum(stacks) == 0 and num_stacks2(stacks) == 0 and num_stacks(stacks) %2 == 0:
        print ("First")
    if nim_sum(stacks) == 0 and num_stacks2(stacks) == 0 and num_stacks(stacks) %2 == 1:
        print ("Second")
    if nim_sum(stacks) == 0 and num_stacks2(stacks) > 0 :
        print ("Second")
 
    if nim_sum(stacks) > 0 and num_stacks(stacks) % 2 == 1 and num_stacks2(stacks) == 0:
        print("Second")
    if nim_sum(stacks) > 0 and num_stacks2(stacks) > 0: 
        print("First")
