class HashTable:
    def __init__(self):
        self.MAX = 10
        self.arr = [[] for i in range(self.MAX)]

    def __setitem__(self, key, value):
        h = self.get_hash(key)
        found = False
        for idx, element in enumerate(self.arr[h]):
            if len(element) == 2 and element[0] == key:
                self.arr[h][idx] = (key, value)
                found = True
        if not found:
            self.arr[h].append((key, value))

    def get_hash(self, key):
        hash = 0
        for i in key:
            hash += ord(i)
        return hash % self.MAX
    
    def _getitem__(self, key):
        h = self.get_hash(key)
        for kv in self.arr[h]:
            if kv[0] == key:
                return kv[1]
    
    def __delitem__(self, key):
        h = self.get_hash(key)
        for index, kv in enumerate(self.arr[h]):
            if kv[0] == key:
                del self.arr[h][index]

if __name__ == '__main__':
    x = HashTable()
    x['MT-15'] = 220000
    x['MT-03'] = 590000
    x['Hornet 2.0'] = 185000
    x['Pulsar N160'] = 165000
    x['Pulsar NS200'] = 195000
    x['KTM Duke 125'] = 230000
    x['KTM Duke 200'] = 250000
    print(x.arr)
    del x['KTM Duke 125']
    print(x.arr)
