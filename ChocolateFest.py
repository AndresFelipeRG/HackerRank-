#!/bin/python3

import sys


t = int(input().strip())
for a0 in range(t):
    n,c,m = input().strip().split(' ')
    n,c,m = [int(n),int(c),int(m)]
    can_buy = int(n/c)
    wrappers = can_buy
    while (can_buy >= m):
        new_choc =  int(can_buy/m)
        wrappers+= new_choc
        choc_left = can_buy%m;
        can_buy = choc_left + new_choc
    print(wrappers)
