import sys

hash = {}

N = int(sys.stdin.readline())
num_arr = list(map(int,sys.stdin.readline().split()))

for i in num_arr:
    hash[i] = 1

M = int(sys.stdin.readline())
check_num = list(map(int,sys.stdin.readline().split()))

for j in check_num:
    if j in hash:
        print(1)
    else:
        print(0)