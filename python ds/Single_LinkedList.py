class Node:
    def __init__(self, data = None, next = None):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None

    def get_print(self):
        if self.head is None:
            print("List is empty.")

        itr = self.head
        lst = ''

        while itr:
            lst += str(itr.data) + '-->' if itr.next else str(itr.data)
            itr = itr.next

        print(lst)

    def length(self):
        count = 0
        itr = self.head

        while itr:
            count += 1
            itr = itr.next

        return count
    
    def insert_start(self, data):
        node = Node(data, self.head)
        self.head = node

    def insert_end(self, data):
        if self.head is None:
            self.head = Node(data, None)
            return
        
        itr = self.head

        while itr.next:
            itr = itr.next

        itr.next = Node(data, None)

    def insert_at_index(self, index, data):
        if index < 0 or index >= self.length():
            raise Exception("Invalid Index")
        
        if index == 0:
            self.insert_start(data)
            return
        
        itr = self.head
        count = 0

        while itr:
            if count == index - 1:
                node = Node(data, itr.next)
                itr.next = node
                break

            itr = itr.next
            count += 1

    def delete_at(self, index):
        if index < 0 or index >= self.length():
            raise Exception("Invalid Index")
        
        if index == 0:
            self.head = self.head.next
            return
        
        count = 0
        itr = self.head

        while itr:
            if count == index - 1:
                itr.next = itr.next.next
                break

            itr = itr.next
            count += 1

if __name__ == '__main__':
    ll = LinkedList()
    ll.insert_start('Yamaha')
    ll.insert_start('YZF')
    ll.insert_end('Honda')
    ll.insert_at_index(2, 'FireBlade')
    ll.insert_end('Aprilia')
    ll.get_print()
    ll.delete_at(4)
    ll.get_print()
