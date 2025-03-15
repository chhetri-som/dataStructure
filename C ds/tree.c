#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree {
    char data[50];
    struct Tree* parent;
    struct Tree** children;
    int child_count;
} Tree;

Tree* create_tree(const char* data) {
    Tree* newTree = (Tree*)malloc(sizeof(Tree));
    strcpy(newTree -> data, data);
    newTree -> parent = NULL;
    newTree -> children = NULL;
    newTree -> child_count = 0;
    return newTree;
}

int level(Tree* tree) {
    int level = 0;
    Tree* p = tree -> parent;
    while (p != NULL) {
        p = p -> parent;
        level++;
    }
    return level;
}

void print_tree(Tree* tree) {
    int lvl = level(tree);
    for(int i = 0; i < lvl; i++) {
        printf("   ");
    }
    if(tree -> parent != NULL) {
        printf("|__");
    }
    printf("%s\n", tree -> data);

    for(int i = 0; i < tree -> child_count; i++) {
        print_tree(tree -> children[i]);
    }
}

void add_child(Tree* parent, Tree* child) {
    child -> parent = parent;
    parent -> child_count++;
    parent -> children = (Tree*)realloc(parent -> children, parent -> child_count * sizeof(Tree*));
    parent -> children[parent -> child_count - 1] = child;
}

Tree* build_tree() {
    Tree* root = create_tree("Motorcycles: ");

    Tree* honda = create_tree("Honda");
    add_child(honda, create_tree("FireBlade CBR 1000RR"));
    add_child(honda, create_tree("CBR 650R"));
    add_child(honda, create_tree("DCT African Twin"));

    Tree* yamaha = create_tree("Yamaha");
    add_child(yamaha, create_tree("YZF R1M"));
    add_child(yamaha, create_tree("MT-09"));
    add_child(yamaha, create_tree("Tenere 900"));

    Tree* ktm = create_tree("KTM");
    add_child(ktm, create_tree("RC 990"));
    add_child(ktm, create_tree("SuperDuke 1290R"));
    add_child(ktm, create_tree("Adventure 690"));

    Tree* aprilia = create_tree("Aprilia");
    add_child(aprilia, create_tree("RSV4"));
    add_child(aprilia, create_tree("Tuono 660"));
    add_child(aprilia, create_tree("RS457"));

    add_child(root, honda);
    add_child(root, yamaha);
    add_child(root, ktm);
    add_child(root, aprilia);

    return root;
}

void free_tree(Tree* tree) {
    for(int i = 0; i < tree -> child_count; i++) {
        free_tree(tree -> children[i]);
    }
    free(tree -> children);
    free(tree);
}

int main()
{
    Tree* root = build_tree();
    print_tree(root);

    free_tree(root);

    return 0;
}
