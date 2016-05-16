n = int(input())


for x in range(n):
    
 
    lst = input().split()
    num = int(lst[0])
    height = int(lst[1])
   
    if height == 1:
        print ("2")
    if num %2 == 0 and height > 1:
        print ("2")
    if num %2 == 1 and height > 1 : 
        print("1")
