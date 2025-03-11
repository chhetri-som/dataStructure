class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node

    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node
        new_node.prev = temp

    def delete_node(self, key):
        temp = self.head
        if temp is None:
            return
        
        while temp and temp.data != key:
            temp = temp.next
        
        if temp is None:
            return
        
        if temp.prev:
            temp.prev.next = temp.next
        else:
            self.head = temp.next
        
        if temp.next:
            temp.next.prev = temp.prev

    def display_forward(self):
        temp = self.head
        while temp:
            print(temp.data, end=' <-> ')
            temp = temp.next
        print('None')

    def display_backward(self):
        temp = self.head
        if temp is None:
            print("List is empty")
            return
        while temp.next:
            temp = temp.next
        while temp:
            print(temp.data, end=' <-> ')
            temp = temp.prev
        print('None')

    def search(self, key):
        temp = self.head
        while temp:
            if temp.data == key:
                return True
            temp = temp.next
        return False

# Example Usage
dll = DoublyLinkedList()
dll.insert_at_end(10)
dll.insert_at_end(20)
dll.insert_at_beginning(5)
dll.insert_at_end(30)

dll.display_forward()  
dll.display_backward()  

dll.delete_node(20)
dll.display_forward()  
