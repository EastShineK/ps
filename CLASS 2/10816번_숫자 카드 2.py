import sys

N = int(sys.stdin.readline())
num_arr = list(map(int,sys.stdin.readline().split()))

M = int(sys.stdin.readline())
check_num = list(map(int,sys.stdin.readline().split()))

for i in range(0, M):
    print(num_arr.count(check_num[i]), end=' ')