#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[50];
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LL;

Node* createNode(const char* data, Node* next){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode -> data, data);
    newNode -> next = next;
    return newNode;
}

void init_linked_list(LL* ll) {
    ll -> head = NULL;
}

void get_print(LL* ll) {
    if(ll -> head == NULL) {
        printf("List is empty. \n");
        return;
    }

    Node* itr = ll -> head;
    while (itr != NULL) {
        printf("%s --> ", itr -> data);
        itr = itr -> next;
    }
    printf("NULL \n");
}

int length(LL* ll) {
    int count = 0;
    Node* itr = ll -> head;

    while(itr != NULL) {
        count++;
        itr = itr -> next;
    }
    return count;
}

void insert_start(LL* ll, const char* data) {
    Node* newNode = createNode(data, NULL);
    ll -> head = newNode;
}

void insert_end(LL* ll, const char* data) {
    if(ll -> head == NULL){
        ll -> head = createNode(data, NULL);
        return;
    }

    Node* itr = ll -> head;
    while(itr ->next != NULL){
        itr = itr -> next;
    }
    itr -> next = createNode(data, NULL);
}

void insert_at_index(LL* ll, int index, const char* data) {
    if(index < 0 || index >= length(ll)) {
        printf("Invalid Index.");
        return;
    }
    if(index == 0) {
        insert_start(ll, data);
        return;
    }

    Node* itr = ll -> head;
    int count = 0;

    while(itr != NULL) {
        if(count == index - 1) {
            Node* newNode = createNode(data, itr -> next);
            itr -> next = newNode;
            break;
        }
        count++;
        itr = itr -> next;
    }
}

void delete_at(LL* ll, int index) {
    if(index < 0 || index > length(ll)){
        printf("Invalid Index.");
        return;
    }

    if(index == 0) {
        Node* temp = ll -> head;
        ll -> head = ll -> head -> next;
        free(temp);
        return;
    }

    Node* itr = ll -> head;
    int count = 0;

    while(itr != NULL) {
        if(count == index - 1) {
            Node* temp = itr -> next;
            itr -> next = itr -> next -> next;
            free(temp);
            break;
        }
        count++;
        itr = itr -> next;
    }
}

int main()
{
    LL ll;
    init_linked_list(&ll);

    insert_start(&ll, "Yamaha");
    insert_start(&ll, "YZF");
    insert_end(&ll, "Honda");
    insert_at_index(&ll, 2, "FireBlade");
    insert_end(&ll, "Aprilia");

    printf("Linked List: ");
    get_print(&ll);

    delete_at(&ll, 4);

    printf("Linked List after deletion: ");
    get_print(&ll);

    // Free remaining nodes (optional, for completeness)
    while (ll.head != NULL) {
        Node* temp = ll.head;
        ll.head = ll.head->next;
        free(temp);
    }

    return 0;
}
