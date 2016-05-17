n = int(input())


for x in range(n):
    
 
    lst = input().split()
    num1 = int(lst[0])
    num2 = int(lst[1])
   
    if num1 % 4 == 1 and num2 %4 == 1:
        print ("Second")
        continue
    if num1 % 4 == 1 and num2 %4 == 2:
        print ("Second")
        continue
    if num1 % 4 == 2 and num2 %4 == 1:
        print ("Second")
        continue
    if num1 % 4 == 2 and num2 %4 == 2:
        print ("Second")
        continue
    else:
        print("First")
