from collections import deque

class Queue:
    def __init__(self):
        self.buffer = deque()

    def enqueue(self, data):
        self.buffer.appendleft(data)

    def dequeue(self):
        print('popped element: ', self.buffer.pop()) 
    
    def length(self):
        print('length: ', len(self.buffer))

    def empty(self):
        if len(self.buffer) == 0:
            print('Queue is empty')
        else:
            print('Queue is NOT empty')

    def display(self):
        string = ''
        for i in range(0, len(self.buffer)):
            string += '-->' + str(self.buffer[i])

        print(string)
        

if __name__ == '__main__':
    q = Queue()
    q.empty()
    q.enqueue('Honda Civic')
    q.enqueue('Honda Acura NSX')
    q.enqueue('Honda S2000')
    q.enqueue('Honda CBR650R')
    q.display()
    q.dequeue()
    q.display()
    q.empty()
    q.length()
