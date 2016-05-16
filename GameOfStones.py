n = int(input())

for x in range(n):
    
    in_d = int(input())
   
    if in_d  % 7 == 0 or (in_d -1) % 7 == 0:
        print("Second")
    if in_d  % 7 != 0 and (in_d -1) % 7 != 0:
        print("First")
