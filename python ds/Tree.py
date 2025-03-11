class Tree:
    def __init__(self, data):
        self.data = data
        self.children = []
        self.parent = None

    def level(self):
        level = 0
        p = self.parent
        while p:
            p = p.parent
            level += 1

        return level
    
    def print_tree(self):
        x = ' ' * self.level() * 3
        y = x + '|__' if self.parent else ''
        print(y + self.data)
        if self.children:
            for child in self.children:
                child.print_tree()

    def add_child(self, child):
        child.parent = self
        self.children.append(child)


def build_tree():
    root = Tree('Motorcycles')

    honda = Tree('Honda')
    honda.add_child(Tree('FireBlade CBR 1000RR'))
    honda.add_child(Tree('CBR 650R'))
    honda.add_child(Tree('DCT African Twin'))

    yamaha = Tree('Yamaha')
    yamaha.add_child(Tree('YZF R1M'))
    yamaha.add_child(Tree('MT-09'))
    yamaha.add_child(Tree('Tenere 900'))

    ktm = Tree('KTM')
    ktm.add_child(Tree('RC 990'))
    ktm.add_child(Tree('SuperDuke 1290R'))
    ktm.add_child(Tree('Adventure 690'))

    aprilia = Tree('Aprilia')
    aprilia.add_child(Tree('RSV4'))
    aprilia.add_child(Tree('Tuono 660'))
    aprilia.add_child(Tree('RS457'))

    root.add_child(honda)
    root.add_child(yamaha)
    root.add_child(ktm)
    root.add_child(aprilia)

    root.print_tree()

if __name__ == '__main__':
    build_tree()
