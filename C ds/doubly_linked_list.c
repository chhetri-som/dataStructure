#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} DLL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
}

void initialize(DLL* dll) {
    dll -> head = NULL;
}

void insertAtBeginning(DLL* dll, int data) {
    Node* newNode = createNode(data);
    if(dll -> head == NULL) {
        dll -> head = newNode;
        return;
    }
    newNode -> next = dll -> head;
    dll -> head -> prev = newNode;
    dll -> head = newNode;
}

void insertAtEnd(DLL* dll, int data) {
    Node* newNode = createNode(data);
    if(dll -> head == NULL) {
        dll -> head = newNode;
        return;
    }
    Node* temp = dll -> head;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> prev = temp;
}

void deleteAt(DLL* dll, int key) {
    Node* temp = dll -> head;

    if (temp == NULL){
        printf("List empty!! \n");
        return;
    }

    while(temp != NULL && temp -> data != key) {
        temp = temp -> next;
    }

    if (temp == NULL) {
        printf("Item not found. \n");
        return;
    }

    if (temp == dll->head) {
        dll->head = temp->next;
        if (dll->head) dll->head->prev = NULL;
    } else {
        temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
    }

    free(temp);
}

void displayForward(DLL* dll) {
    if (dll->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = dll -> head;
    printf("Forward: ");
    while(temp != NULL) {
        printf("%d <-> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL \n");
}

void displayBackward(DLL* dll) {
    if (dll->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = dll->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int search(DLL* dll, int key) {
    Node* temp = dll -> head;
    while(temp != NULL) {
        if(temp -> next == key) {
            return 1;
        }
    }
    return 0;
}

int main() {

    DLL dll;
    initialize(&dll);

    insertAtEnd(&dll, 10);
    insertAtEnd(&dll, 20);
    insertAtBeginning(&dll, 5);
    insertAtEnd(&dll, 30);

    displayForward(&dll);
    displayBackward(&dll);

    printf("Deleting 20...\n");
    deleteAt(&dll, 20);
    displayForward(&dll);

    printf("Searching for 10: %s\n", search(&dll, 10) ? "Found" : "Not Found");
    printf("Searching for 50: %s\n", search(&dll, 50) ? "Found" : "Not Found");

    return 0;

}
