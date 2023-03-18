import sys

hash = {}

N = int(sys.stdin.readline())
num_arr = list(map(int,sys.stdin.readline().split()))

for j in num_arr:
    if j in hash:
        hash[j] += 1
    else:
        hash[j] = 1

M = int(sys.stdin.readline())
check_num = list(map(int,sys.stdin.readline().split()))

for i in check_num:
    if i in hash:
        print(hash[i], end=' ')
    else:
        print(0, end=' ')