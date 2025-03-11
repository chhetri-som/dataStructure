class BinarySearchTree:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def add_child(self, data):
        if data == self.data:
            return
        if data < self.data:
            if self.left:
                self.left.add_child(data)
            else:
                self.left = BinarySearchTree(data)
        else:
            if self.right:
                self.right.add_child(data)
            else:
                self.right = BinarySearchTree(data)

    def search(self, data):
        if self.data == data:
            return True
        
        if data < self.data:
            if self.left:
                return self.left.search(data)
            else:
                return False
            
        else:
            if self.right:
                return self.right.search(data)
            else:
                return False
            
    def InorderTraversal(self):
        elements = []
        if self.left:
            elements += self.left.InorderTraversal()

        elements.append(self.data)

        if self.right:
            elements += self.right.InorderTraversal()

        return elements
    
    def PostorderTraversal(self):
        elements = []
        if self.left:
            elements += self.left.PostorderTraversal()

        if self.right:
            elements += self.right.PostorderTraversal()

        elements.append(self.data)

        return elements
    
    def PreorderTraversal(self):
        elements = []

        elements.append(self.data)

        if self.left:
            elements += self.left.PostorderTraversal()

        if self.right:
            elements += self.right.PostorderTraversal()

        return elements
    
def build_tree(elements):
    print(f'Elements of tree: {elements}')
    root = BinarySearchTree(elements[0])

    for i in range(1, len(elements)):
        root.add_child(elements[i])

    return root

if __name__ == '__main__':
    cars = ['Lancia Stratos', 'BMW E46', 'Toyota Camry', 'Ferrari F40', 'Peugot Evo II T16']
    car_tree = build_tree(cars)

    print('Is BMW E46 in the list??', car_tree.search('BMW E46'))
    
    x = [23, 45, 24, 90, 56, 1, 24, 76, 4, 55, 23, 98, 20]
    num_tree = build_tree(x) 
    print(f'In-order Traversal: {num_tree.InorderTraversal()}')
    print(f'Pre-order Traversal: {num_tree.PreorderTraversal()}')
    print(f'Post-order Traversal: {num_tree.PostorderTraversal()}')
