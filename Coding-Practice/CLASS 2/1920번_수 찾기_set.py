import sys

N = sys.stdin.readline()
num_arr = set(sys.stdin.readline().split())
M = sys.stdin.readline()

for j in sys.stdin.readline().split():
    if j in num_arr:
        print(1)
    else:
        print(0)