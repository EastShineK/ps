import sys
from collections import deque

def add(x, S):
    S.add(x)
        
def remove(x, S):
    S.discard(x)
        
def check(x, S):
    if x in S:
        return '1'
    else:
        return '0'
        
def toggle(x, S):
    if x in S:
        S.remove(x)
    else:
        S.add(x)
        
def all_s(S):
    S.clear()
    S.update(range(1, 21))
        
def empty(S):
    S.clear()
    
if __name__ == '__main__':
    
    print = sys.stdout.write
    
    num = int(input())
    S = set([])
    
    for _ in range(num):
        command = list(sys.stdin.readline().split())

        if command[0] == 'check':
            print(check(int(command[1]), S)+'\n')
        elif command[0] == 'add':
            add(int(command[1]), S)
        elif command[0] == 'toggle':
            toggle(int(command[1]), S)
        elif command[0] == 'remove':
            remove(int(command[1]), S)
        elif command[0] == 'all':
            all_s(S)
        elif command[0] == 'empty':
            empty(S)  