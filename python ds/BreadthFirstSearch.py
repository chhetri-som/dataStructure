def bfs(data, start, visited=set()):

    queue = [start]

    while queue:
        current_node = queue.pop(0)
        if current_node not in visited:
            print(current_node, end=" ")
        visited.add(current_node)

        for i in data[current_node] - visited:
            queue.append(i)
    return


if __name__ == '__main__':

    data = {
        'A': {'B', 'C'},
        'B': {'A', 'D', 'E'},
        'C': {'A', 'F', 'G'},
        'D': {'B', 'H'},
        'E': {'B', 'I', 'J'},
        'F': {'C'},
        'G': {'C', 'K'},
        'H': {'D'},
        'I': {'E'},
        'J': {'E', 'L'},
        'K': {'G'},
        'L': {'J'}
    }

    bfs(data, 'A')