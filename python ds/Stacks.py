from collections import deque

class Stack:
    def __init__(self):
        self.container = deque()

    def push(self, data):
        self.container.append(data)

    def pop(self):
        return self.container.pop()
    
    def peek(self):
        return self.container[-1]
    
    def empty(self):
        if len(self.container) == 0:
            print("Stack is empty")
        else:
            print("Stack is NOT empty")
    
    def length(self):
        print('length:', len(self.container)) 
    
    def display(self):
        for x in range(0, len(self.container)):
            print(self.container[x])
    
if __name__ == '__main__':
    s = Stack()
    s.push(23.2)
    s.push(45.6)
    s.push(34.9)
    s.display()
    s.pop()
    s.push(69.9)
    s.display()
    s.length()
    s.empty()
