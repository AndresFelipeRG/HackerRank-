 
inp = input().strip().split()
k, m, d = [int(inp[0]), int(inp[1]), int(inp[2])]
lst = [[0,x] for x in range(m+1)]
orders = [[x,[]] for x in  range(d+1)]

    
for i in range(d):
    num = int(input())
    lst[num][0]= lst[num][0]+1
lst.sort()
#print(lst)
for [a,b] in lst:
    orders[a][1] += [b]
#print(orders)
ids = []
for z in range(len(orders)):
    
    ids += orders[len(orders)-1-z][1]
#print(ids)
for p in range(k):
    print(ids[p])
