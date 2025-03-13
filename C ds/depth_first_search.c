#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct Node{
    char vertex;
    struct Node* next;
} Node;

typedef struct {
    char vertices[MAX_NODES];
    int size;
    Node* adjacencyList[MAX_NODES];
} Graph;

typedef struct {
    char items[MAX_NODES];
    int top;
} Stack;

void initializeStack(Stack* stack) {
    stack -> top = -1;
}

char push(Stack* stack, char value) {
    if(stack -> top < MAX_NODES - 1){
        stack -> items[++(stack -> top)] = value;
    } else {
        printf("Stack Overflow!! \n");
    }
}

char pop(Stack* stack) {
    if(stack -> top >= 0) {
        return stack -> items[(stack -> top)--];
    }
    return '\0';
}

int isStackEmpty(Stack* stack) {
    return stack -> top == -1;
}

Node* createNode(char vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> vertex = vertex;
    newNode -> next = NULL;
    return newNode;
}

void initializeGraph(Graph* graph) {
    graph -> size = 0;
    for(int i = 0; i < MAX_NODES; i++) {
        graph -> adjacencyList[i] = NULL;
    }
}

void addVertex(Graph* graph, char vertex) {
    graph -> vertices[graph -> size++] = vertex;
}

void addEdge(Graph* graph, char src, char dest) {
    int i;
    for(int i = 0; i < graph -> size; i++) {
        if(graph -> vertices[i] == src){
            Node* newNode = createNode(dest);
            newNode -> next = graph -> adjacencyList[i];
            graph -> adjacencyList[i] = newNode;
            break;
        }
    }
}

int findVertexIndex(Graph* graph, char vertex) {
    for(int i = 0; i < graph -> size; i++) {
        if(graph -> vertices[i] == vertex) {
            return i;
        }
    }
    return -1;
}

void dfs(Graph* graph, char startVertex) {
    int visited[MAX_NODES] = {0};
    Stack stack;
    initializeStack(&stack);

    push(&stack, startVertex);

    while(!isStackEmpty(&stack)) {
        char current = pop(&stack);
        int index = findVertexIndex(graph, current);

        if(!visited[index]) {
            printf("%c, ", current);
            visited[index] = 1;
        }
        Node* temp = graph -> adjacencyList[index];
        while(temp) {
            if(!visited[findVertexIndex(graph, temp -> vertex)]) {
                push(&stack, temp -> vertex);
           }
           temp = temp -> next;
        }
    }
}

int main()
{
    Graph graph;
    initializeGraph(&graph);

    // Add vertices
    addVertex(&graph, 'A');
    addVertex(&graph, 'B');
    addVertex(&graph, 'C');
    addVertex(&graph, 'D');
    addVertex(&graph, 'E');
    addVertex(&graph, 'F');
    addVertex(&graph, 'G');
    addVertex(&graph, 'H');
    addVertex(&graph, 'I');
    addVertex(&graph, 'J');
    addVertex(&graph, 'K');
    addVertex(&graph, 'L');

    // Add edges
    addEdge(&graph, 'A', 'B');
    addEdge(&graph, 'A', 'C');
    addEdge(&graph, 'B', 'A');
    addEdge(&graph, 'B', 'D');
    addEdge(&graph, 'B', 'E');
    addEdge(&graph, 'C', 'A');
    addEdge(&graph, 'C', 'F');
    addEdge(&graph, 'C', 'G');
    addEdge(&graph, 'D', 'B');
    addEdge(&graph, 'D', 'H');
    addEdge(&graph, 'E', 'B');
    addEdge(&graph, 'E', 'I');
    addEdge(&graph, 'E', 'J');
    addEdge(&graph, 'F', 'C');
    addEdge(&graph, 'G', 'C');
    addEdge(&graph, 'G', 'K');
    addEdge(&graph, 'H', 'D');
    addEdge(&graph, 'I', 'E');
    addEdge(&graph, 'J', 'E');
    addEdge(&graph, 'J', 'L');
    addEdge(&graph, 'K', 'G');
    addEdge(&graph, 'L', 'J');

    printf("Depth First Search starting from A: ");
    dfs(&graph, 'A');

    return 0;
}
