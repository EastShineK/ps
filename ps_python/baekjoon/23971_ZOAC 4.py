import sys
from collections import deque

if __name__ == '__main__':
    H, W, N, M = map(int, input().split())
    print = sys.stdout.write
    
    #print(str(H)), print(str(W)),print(str(N)),print(str(M))
    
    a = (H - 1) / (N + 1) + 1
    b = (W - 1) / (M + 1) + 1
    
    #print(str(int(a))+'\n')
    #print(str(int(b))+'\n')
    print(str(int(a)*int(b)))
    

    
    #1+(1+N)*a < H, 1+(1+M)*b < W
    
    #2*b < 3 (1+M)*b < W -1 
    #b = 3/2 = 1.5 = 1 => 한줄에 2명
    
    #(1+1)*a < 4     (1+N)*a < H-1
    #a = 4/2 = 2 => 3개의 행 가능