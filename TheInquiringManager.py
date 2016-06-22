intervals = []
queries = []
events = []
leng = 0
time = 0
events = int(input())
last_querie = [-1,-1]
first = False
last_index = 0
timer = 0
def find_max(lst, min_time, length):
    curr_max = -1
    time = 0
    val = length
    for y in range(length):
        if(lst[val-1-y][1]< min_time):
            return [curr_max,time]
        if lst[val-1-y][0] >= curr_max:
            curr_max = lst[val-1-y][0]
            time = lst[val-1-y][1]
    return [curr_max,time]  
for x in range(events):
    eve = input().strip().split()
    
    if(int(eve[0]) == 1):
        max_querie = int(eve[2])+ 59
        if(int(eve[1]) > last_querie[0] and first):
            last_querie[0]  = int(eve[1]) 
            last_querie[1]  = int(eve[2]) 
        leng+=1
        intervals += [[int(eve[1]),int(eve[2]), max_querie]]
        continue
    queries += [int(eve[1])]
    time = int(eve[1])
    if(time >= last_querie[1] and time-59 <= last_querie[1] and  first ):
        print(last_querie[0])
        
        continue
    [last_querie[0], last_querie[1]] = find_max(intervals,int(eve[1])-59,leng)
   
    first = True
    print(last_querie[0])
#print(intervals)
#print(queries)
