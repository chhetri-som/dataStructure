#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char data[50];
    struct Node *left, *right;
} Node;

Node* createNode(const char *data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode -> data, data);
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

Node* insert(Node* root, const char *data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (strcmp(data, root -> data) < 0){
        root -> left = insert(root -> left, data);
    } else if (strcmp(data, root -> data) > 0) {
        root -> right = insert(root -> right, data);
    }
    return root;
}

int search(Node* root, const char *data) {
    if (root == NULL) {
        return 0;
    }
    if (strcmp(data, root -> data) == 0) {
        return 1;
    }
    if (strcmp(data, root -> data) < 0) {
        return search(root -> left, data);
    } else {
        return search(root -> right, data);
    }
}

void inorderTraversal(Node* root) {
    if(root != NULL) {
        inorderTraversal(root -> left);
        printf("%s, ", root -> data);
        inorderTraversal(root -> right);
    }
}

void preorderTraversal(Node* root) {
    if(root != NULL) {
        printf("%s, ", root -> data);
        preorderTraversal(root -> left);
        preorderTraversal(root -> right);
    }
}

void postorderTraversal(Node* root) {
    if(root != NULL) {
        postorderTraversal(root -> left);
        postorderTraversal(root -> right);
        printf("%s, ", root -> data);
    }
}

Node* buildTree (char *elements[], int size) {
    printf("Elements of tree: ");
    for (int i = 0; i < size; i++){
        printf("%s, ", elements[i]);
    }
    printf("\n");

    Node* root = createNode(elements[0]);
    for (int i = 1; i < size; i++) {
        insert(root, elements[i]);
    }
    return root;
}

int main()
{
    char *cars[] = {"Lancia Stratos", "BMW E46", "Toyota Camry", "Ferrari F40", "Peugeot Evo II T16"};
    int carSize = sizeof(cars) / sizeof(cars[0]);
    Node* cartree = buildTree(cars, carSize);

    printf("\nIs BMW E46 in the list?? %s \t", search(cartree, "BMW E46") ? "Yes" : "No");

    int numbers[] = {23, 45, 24, 90, 56, 1, 24, 76, 4, 55, 23, 98, 20};
    int numSize = sizeof(numbers)/sizeof(numbers[0]);
    Node* numtree = NULL;

    for (int i = 0; i < numSize; i++) {
        char str[10];
        sprintf(str, "%d", numbers[i]);
        numtree = insert(numtree, str);
    }

    printf("\nInorder Traversal: ");
    inorderTraversal(numtree);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorderTraversal(numtree);
    printf("\n");

    printf("Post-order Traversal: ");
    postorderTraversal(numtree);
    printf("\n");

    return 0;
}
