import sys

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class Deque_d:
    def __init__(self):
        self.front = None
        self.rear = None
        self.size = 0
    
    def push_front_dq(self, num):
        new_Node = Node(num)
        
        if self.empty_dq():
            self.front = new_Node
            self.rear = new_Node
        else:
            self.front.prev = new_Node
            new_Node.next = self.front
            self.front = new_Node
        self.size += 1
        
    def push_back_dq(self, num):
        new_Node = Node(num)
        
        if self.empty_dq():
            self.front = new_Node
            self.rear = new_Node
        else:
            new_Node.prev = self.rear
            if self.rear:
                self.rear.next = new_Node
                self.rear = self.rear.next
        self.size += 1

    def pop_front_dq(self):
        if self.empty_dq():
            print(-1)
        else:
            print(self.front.data)
            self.front = self.front.next
        
        if self.size > 0:   
            self.size -= 1
            
    def pop_back_dq(self):
        if self.empty_dq():
            print(-1)
        else:
            print(self.rear.data)
            self.rear = self.rear.prev
            if self.rear:
                self.rear.next = None
        
        if self.size > 0:   
            self.size -= 1

        
    def size_dq(self):
        return self.size
        
    def empty_dq(self):
        if self.size_dq():
            return 0
        else:
            return 1
            
    def front_dq(self):
        if self.empty_dq():
            print(-1)
        else:
            print(self.front.data)
            
    def back_dq(self):
        if self.empty_dq():
            print(-1)
        else:
            print(self.rear.data)

if __name__ == '__main__':
    N = int(sys.stdin.readline())
    
    my_deque = Deque_d()

    for i in range(0, N):
        inst = sys.stdin.readline().rstrip()

        if inst.find('push') != -1:
            k = inst.split()
            inst = k[0]
            num = k[1]

        if inst == 'push_front':
            my_deque.push_front_dq(num)
        
        elif inst == 'push_back':
            my_deque.push_back_dq(num)
            
        elif inst == 'pop_front':
            my_deque.pop_front_dq()
        
        elif inst == 'pop_back':
            my_deque.pop_back_dq()
            
        elif inst == 'size':
            size_a = my_deque.size_dq()
            print(size_a)
            
        elif inst == 'empty':
            res = my_deque.empty_dq()
            print(res)
            
        elif inst == 'front':
            my_deque.front_dq()
            
        elif inst == 'back':
            my_deque.back_dq()