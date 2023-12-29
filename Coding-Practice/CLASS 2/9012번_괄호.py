import sys

class Stack:
    def __init__(self):
        self.stack = []
        self.size = 0
    
    def push_s(self, data):
        self.stack.append(data)
        self.size += 1
    
    def pop_s(self):
        if self.empty_s():
            return -1
        else:
            self.stack.pop(-1)
            self.size -= 1
        
    def top_s(self):
        if self.empty_s():
            return -1
        else:
            return self.stack[-1]
    
    def size_s(self):
        return self.size
        
    def empty_s(self):
        if self.size == 0:
            return 1
        else:
            return 0

if __name__ == '__main__':
    N = int(sys.stdin.readline())
    print_t = sys.stdout.write
    input = []
    
    for i in range(0, N):
        result = 1
        stack = Stack()
        input = list(sys.stdin.readline().rstrip())
        for i in range(0, len(input)):
            if input[i] == '(':
                stack.push_s(input[i])
            else:
                top = stack.top_s()
                if top == '(':
                    stack.pop_s()
                else:
                    result = 0
                    break;
                    
        if not stack.empty_s():
            result = 0
            
        if result == 1:
            print_t('YES'+"\n")
        else:
            print_t('NO'+"\n")