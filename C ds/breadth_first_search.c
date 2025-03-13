#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct{
    char* items[MAX_NODES];
    int front, rear;
} Queue;

void initializerQueue(Queue *q) {
    q -> front = q -> rear = -1;
}

int isEmpty(Queue* q) {
    return q -> front == -1;
}

void enqueue(Queue* q, char* data) {
    if(q -> rear == MAX_NODES - 1){
        printf("Queue is full!! \n");
        return;
    }
    if(isEmpty(q)) {
        q -> front = 0;
    }
    q -> rear++;
    q -> items[q -> rear] = data;
}

char* dequeue(Queue* q) {
    if(isEmpty(q)){
        printf("Queue is empty!! \n");
        return;
    }
    char* item = q -> items[q -> front];
    if(q -> front == q -> rear) {
        q -> front = q -> rear = -1;
    } else {
        q -> front++;
    }
    return item;
}

typedef struct {
    char* nodes[MAX_NODES];
    int adjMatrix[MAX_NODES][MAX_NODES];
    int size;
} Graph;

void initializerGraph(Graph* g){
    g -> size = 0;
    memset(g -> adjMatrix, 0, sizeof(g -> adjMatrix));
}

int findNodeIndex(Graph* g, char* node) {
    for(int i = 0; i < g -> size; i++){
        if(strcmp(g -> nodes[i], node) == 0) {
            return i;
        }
    }
    return -1;
}

void addNode(Graph* g, char* node) {
    if(findNodeIndex(g, node) == -1) {
        g -> nodes[g -> size] = node;
        g -> size++;
    }
}

void addEdge(Graph* g, char* src, char* dest) {
    int srcIndex = findNodeIndex(g, src);
    int destIndex = findNodeIndex(g, dest);

    if(srcIndex != -1 && destIndex != -1) {
        g -> adjMatrix[srcIndex][destIndex] = 1;
        g -> adjMatrix[destIndex][srcIndex] = 1;
    }
}

void bfs(Graph* g, char* start) {
    Queue q;
    initializerQueue(&q);

    int visited[MAX_NODES] = {0};
    int startIndex = findNodeIndex(g, start);

    if(startIndex == -1) {
        printf("Start node not found!! \n");
        return;
    }

    enqueue(&q, start);
    visited[startIndex] = 1;

    while(!isEmpty(&q)) {
        char* currentNode = dequeue(&q);
        printf("%s, ", currentNode);

        int currentIndex = findNodeIndex(g, currentNode);
        for(int i = 0; i < g -> size; i++){
            if(g -> adjMatrix[currentIndex][i] == 1 && !visited[i]) {
                enqueue(&q, g -> nodes[i]);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main()
{
    Graph g;
    initializerGraph(&g);

    char* nodes[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L"};
    int numNodes = sizeof(nodes)/sizeof(nodes[0]);
    for(int i = 0; i < numNodes; i++){
        addNode(&g, nodes[i]);
    }

    addEdge(&g, "A", "B");
    addEdge(&g, "A", "C");
    addEdge(&g, "B", "D");
    addEdge(&g, "B", "E");
    addEdge(&g, "C", "F");
    addEdge(&g, "C", "G");
    addEdge(&g, "D", "H");
    addEdge(&g, "E", "I");
    addEdge(&g, "E", "J");
    addEdge(&g, "G", "K");
    addEdge(&g, "J", "L");

    printf("BFS Traversal: ");
    bfs(&g, "A");

    return 0;
}
