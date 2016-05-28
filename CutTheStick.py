#!/bin/python3

import sys

def minimum_no_zero(lst):
    mini = -1
    if len(lst)>0 :
        
        mini = 1000
    for i in range(len(lst)):
        if lst[i]< mini and lst[i] > 0:
            mini = lst[i]
    return mini
n = int(input().strip())
arr = [int(arr_temp) for arr_temp in input().strip().split(' ')]
while sum(arr) > 0:
    mini = minimum_no_zero(arr)
    count = 0
    for i in range(len(arr)):
        if arr[i] > 0:
            arr[i]= arr[i]-mini
            count+=1
    print(count)
