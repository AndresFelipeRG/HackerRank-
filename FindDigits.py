#!/bin/python3

import sys


t = int(input().strip())

for a0 in range(t):
    n = int(input().strip())
    count = 0
    original = n
    while n >=1:
        num = n%10
        if num == 0:
            n =int(n/10)
            continue
        if (original %(num)) == 0:
            count+=1
        n=int(n/10)
    print (count)
