import sys
from collections import deque

if __name__ == '__main__':
    N = int(sys.stdin.readline())
    print = sys.stdout.write
    deque = deque()
    for i in range(0, N):
        deque.append(i+1)
        
    while(len(deque) > 1):
        deque.popleft()
        num = deque.popleft()
        deque.append(num)
    print(str(deque[0]))