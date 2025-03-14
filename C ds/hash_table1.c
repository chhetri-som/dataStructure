#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char key[50];
    int value;
} HashItem;

typedef struct {
    HashItem *arr[MAX];
} HashTable;

int hash(char *data) {
    int hash = 0;
    for(int i = 0; data[i] != '\0'; i++) {
        hash += data[i];
    }
    return hash % MAX;
}

void initHashTable(HashTable *ht) {
    for (int i = 0; i < MAX; i++) {
        ht -> arr[i] = NULL;
    }
}

void insert(HashTable *ht, char *key, int value) {
    int index = hash(key);
    HashItem *newItem = (HashItem *)malloc(sizeof(HashItem));
    strcpy(newItem -> key, key);
    newItem -> value = value;
    ht -> arr[index] = newItem;
}

int get(HashTable *ht, char *key) {
    int index = hash(key);
    if(ht -> arr[index] != NULL && strcmp(ht -> arr[index] -> key, key) == 0) {
        return ht -> arr[index] -> value;
    }
    return -1;
}

void delete(HashTable *ht, char *key) {
    int index = hash(key);
    if(ht -> arr[index] != NULL && strcmp(ht -> arr[index] -> key, key) == 0) {
        free(ht -> arr[index]);
        ht -> arr[index] = NULL;
    }
}

void printHashTable(HashTable *ht) {
    printf("Hash Table: \n");
    for(int i = 0; i < MAX; i++) {
        if(ht -> arr[i] != NULL) {
            printf("Index %d: (%s, %d) \n", i, ht -> arr[i] -> key, ht -> arr[i] -> value);
        }
    }
}

int main()
{
    HashTable ht;
    initHashTable(&ht);

    insert(&ht, "MT-15", 220000);
    insert(&ht, "Hornet 2.0", 180000);
    insert(&ht, "CB300R", 300000);
    insert(&ht, "Duke 125", 230000);

    delete(&ht, "Hornet 2.0");

    printHashTable(&ht);

    return 0;
}
