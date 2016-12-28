#link https://www.hackerrank.com/contests/zalando-codesprint/challenges/wrappingsurfacearea
import math
n = int(input().strip())
a,b,c = [int(j) for j in input().split()]
vol = n*a*b*c
d = vol**(1.0/3.0)
#s = math.floor(max(d/a, d/b, d/c))
#print(d/a, d/b, d/c)
a11 = math.floor(d/a)-1
a12 = math.floor(d/b)-1
a13 = math.floor(d/c)-1
#print(a11, a12, a13)
if a11 <= 0:
    a11 = 1
if a12 <= 0:
    a12 = 1
if a13 <= 0:
    a13 = 1
if a11 >= 3:
    a11 = a11-1
if a12 >= 3:
    a12 = a12-1
if a13 >= 3:
    a13 = a13-2

dimensions = []

def area(a,b,c):
    return 2*(a*b + b*c + a*c)
def dimensions(a1,b1,c1,x,y,z,n):
    if(x*y*z >= n):
        return area(a1*x,b1*y,c1*z)
    else:
        return min(dimensions(a1,b1,c1,x+1,y,z,n),dimensions(a1,b1,c1,x,y+1,z,n),dimensions(a1,b1,c1,x,y,z+1,n))
print(dimensions(a,b,c,a11,a12,a13,n))
