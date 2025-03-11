# function for depth first search
def dfs(data, start, visited=set()):

    # if not visited print it
    if start not in visited:
        print(start, end=" ")

    visited.add(start)

    for i in data[start] - visited:

        # if not visited gi in depth of it
        dfs(data, i, visited)
    return


# sample data in dictionary form
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



if __name__ == '__main__':

    dfs(data, 'A')