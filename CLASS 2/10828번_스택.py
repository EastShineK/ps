import sys

if __name__ == '__main__':
    N = int(sys.stdin.readline())
    stack = []
    
    for i in range(0, N):
        inst = sys.stdin.readline().rstrip()
        if inst.find('push') != -1:
            k = inst.split()
            inst = k[0]
            num = k[1]
        
        if inst == 'push':
            stack.append(num)
        elif inst == 'pop':
            if len(stack) == 0:
                print(-1)
            else:
                print(stack[-1])
                stack.pop(-1)
        elif inst == 'size':
            print(len(stack))
        elif inst == 'empty':
            if len(stack) == 0:
                print(1)
            else:
                print(0)
        elif inst == 'top':
            if len(stack) == 0:
                print(-1)
            else:
                print(stack[-1])