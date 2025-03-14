#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    char key[50];
    int value;
} KeyValuePair;

typedef struct {
    KeyValuePair* buckets[MAX];
    int sizes[MAX];
} HashTable;

int get_hash(const char* key) {
    int hash = 0;
    for(int i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return hash % MAX;
}

void init_hash_table(HashTable* ht) {
    for(int i = 0;i < MAX; i++) {
        ht -> buckets[i] = (KeyValuePair*)malloc(10 * sizeof(KeyValuePair));
        ht -> sizes[i] = 0;
    }
}

void set_item(HashTable* ht, const char* key, int value) {
    int h = get_hash(key);
    int found = 0;

    for(int i = 0; i < ht -> sizes[h]; i++) {
        if(strcmp(ht -> buckets[h][i].key, key) == 0) {
            ht -> buckets[h][i].value = value;
            found = 1;
            break;
        }
    }

    if(!found) {
        strcpy(ht -> buckets[h][ht -> sizes[h]].key, key);
        ht -> buckets[h][ht -> sizes[h]].value = value;
        ht -> sizes[h]++;
    }
}

int get_item(HashTable* ht, const char* key) {
    int h = get_hash(key);

    for(int i = 0; i < ht -> sizes[h]; i++) {
        if(strcmp(ht -> buckets[h][i].key, key) == 0) {
            return ht -> buckets[h][i].value;
        }
    }
    return -1;
}

void del_item(HashTable* ht, const char* key) {
    int h = get_hash(key);

    for(int i = 0; i < ht -> sizes[h]; i++) {
        if(strcmp(ht -> buckets[h][i].key, key) == 0) {
            for(int j = i; j < ht -> sizes[h] - 1; j++) {
                strcpy(ht -> buckets[h][j].key, ht -> buckets[h][j + 1].key);
                ht -> buckets[h][j].value = ht -> buckets[h][j + 1].value;
            }
            ht -> sizes[h]--;
            break;
        }
    }
}

void print_hash_table(HashTable* ht) {
    for(int i = 0; i < MAX; i++) {
        printf("Bucket %d: ", i);
        for(int j = 0; j < ht -> sizes[i]; j++) {
            printf("(%s, %d)", ht -> buckets[i][j].key, ht -> buckets[i][j].value);
        }
        printf("\n");
    }
}

int main()
{
    HashTable ht;
    init_hash_table(&ht);

    // Insert key-value pairs
    set_item(&ht, "MT-15", 220000);
    set_item(&ht, "MT-03", 590000);
    set_item(&ht, "Hornet 2.0", 185000);
    set_item(&ht, "Pulsar N160", 165000);
    set_item(&ht, "Pulsar NS200", 195000);
    set_item(&ht, "KTM Duke 125", 230000);
    set_item(&ht, "KTM Duke 200", 250000);

    // Print the hash table
    printf("Hash Table Contents:\n");
    print_hash_table(&ht);

    // Delete a key-value pair
    del_item(&ht, "KTM Duke 125");

    // Print the hash table after deletion
    printf("\nHash Table Contents after deletion:\n");
    print_hash_table(&ht);

    // Free allocated memory
    for (int i = 0; i < MAX; i++) {
        free(ht.buckets[i]);
    }

    return 0;
}
