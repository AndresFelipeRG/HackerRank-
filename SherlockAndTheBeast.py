#!/bin/python3

import sys
def digits(n):
    cn = 0
    num5s = n
    init = n
    val = ""
    if init %3 == 0:
        return "555"*(int(n/3))
    while init > 1:
        if init % 3 == 0 and (n-init)%5 == 0:
            val = "555"*(int((init)/3))
            val = val + "33333"*(int(((n-init))/5))
            return val
        init -= 1
       
    if n % 5 == 0:
        return "33333"*(int(n/5))
    return "-1"
t = int(input().strip())
for ao in range(t):
    n = int(input().strip())
    print(digits(n))
    
