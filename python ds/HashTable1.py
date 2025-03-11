class HashTable:
    def __init__(self):
        self.MAX = 100
        self.arr = [None for i in range(self.MAX)]

    def hash(self, data):
        hash = 0
        for x in data:
            hash += ord(x)
        return hash % self.MAX
    
    def __setitem__(self, key, data):
        x = self.hash(key)
        self.arr[x] = data

    def __getitem__(self, key):
        x = self.hash(key)
        return self.arr[x]
    
    def __delitem__(self, key):
        x = self.hash(key)
        self.arr[x] = None

if __name__ == '__main__':
    h = HashTable()
    h['MT-15'] = 220000
    h['Hornet 2.0'] = 180000
    h['CB300R'] = 300000
    h['Duke 125'] = 230000
    del h['Hornet 2.0']
    print(h.arr)
