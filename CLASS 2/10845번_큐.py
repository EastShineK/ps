import sys

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None
        self.size = 0
    
    def push_q(self, num):
        new_Node = Node(num)
        
        if self.front is None:
            self.front = new_Node
            self.rear = new_Node
        else:
            self.rear.next = new_Node
            self.rear = self.rear.next
        self.size += 1

    def pop_q(self):
        if self.empty_q():
            print(-1)
        else:
            print(self.front.data)
            self.front = self.front.next
        
        if self.size > 0:   
            self.size -= 1
        
    def size_q(self):
        print(self.size)
        
    def empty_q(self):
        if self.front is None:
            return 1
        else:
            return 0
            
    def front_q(self):
        if self.empty_q():
            print(-1)
        else:
            print(self.front.data)
            
    def back_q(self):
        if self.empty_q():
            print(-1)
        else:
            print(self.rear.data)

if __name__ == '__main__':
    N = int(sys.stdin.readline())
    
    my_queue = Queue()

    for i in range(0, N):
        inst = sys.stdin.readline().rstrip()
        
        if inst.find('push') != -1:
            k = inst.split()
            inst = k[0]
            num = k[1]

        if inst == 'push':
            my_queue.push_q(num)
            
        elif inst == 'pop':
            my_queue.pop_q()
            
        elif inst == 'size':
            my_queue.size_q()
            
        elif inst == 'empty':
            res = my_queue.empty_q()
            print(res)
            
        elif inst == 'front':
            my_queue.front_q()
            
        elif inst == 'back':
            my_queue.back_q()