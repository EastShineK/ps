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
            return -1
        else:
            a = self.front.data
            self.front = self.front.next
        
        if self.size > 0:   
            self.size -= 1
        return a
        
    def size_q(self):
        return self.size
        
    def empty_q(self):
        if self.front is None:
            return 1
        else:
            return 0
            
    def front_q(self):
        if self.empty_q():
            return -1
        else:
            return self.front.data

if __name__ == '__main__':
    N = int(sys.stdin.readline())
    print = sys.stdout.write
    my_queue = Queue()

    for i in range(0, N):
        my_queue.push_q(i+1)

    cnt = 0
    while my_queue.size_q() != 1:
        if cnt == 0:
            t = my_queue.pop_q()
            cnt = 1
        else:
            tmp = my_queue.pop_q()
            my_queue.push_q(tmp)
            cnt = 0
    print(str(my_queue.front_q())+"\n")