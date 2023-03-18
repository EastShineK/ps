import sys

all_num = [0 for i in range(20000001)]
N = int(sys.stdin.readline())
num_arr = list(map(int,sys.stdin.readline().split()))

for j in range(0, N):
    all_num[num_arr[j]+10000000]+= 1

M = int(sys.stdin.readline())
check_num = list(map(int,sys.stdin.readline().split()))

for i in range(0, M):
    print(all_num[check_num[i]+10000000], end=' ')