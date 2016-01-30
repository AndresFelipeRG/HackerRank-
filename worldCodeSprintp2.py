
import sys

def find_min(element, cities):
    mini = 100000
    for i in cities:
        if abs(element-i) <= mini:
            mini = abs(element-i)
    return mini
        
n,m = raw_input().strip().split(' ')
n,m = [int(n),int(m)]
c = map(int,raw_input().strip().split(' '))
c.sort()
j = 0
lst = []
last_index = 0
if n == m:
    print 0
else:
    for i in range(n):
        if i in c:
            lst.append(0)
            #if(last_index >=0):
                # c.remove(last_index)
            last_index = c.index(i)
            continue
        
        else:
            if(last_index+ 2 <=m):
                lst.append(find_min(i,c[last_index:last_index+2]))
            else:
                lst.append(find_min(i,c[last_index:]))
        
    print max(lst)  
