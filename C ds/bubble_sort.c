#include <stdio.h>

void BubbleSort(int elements[], int size) {
    int swapped;

    for(int i = 0; i < size - 1; i++) {
        swapped = 0;
        for(int j = 0; j < size - 1; j++) {
            if(elements[j] > elements[j + 1]){
                int temp = elements[j];
                elements[j] = elements[j + 1];
                elements[j + 1] = temp;

                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
}

void printArray(int elements[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d, ", elements[i]);
    }
    printf("\n");
}

int main()
{
    int x[] = {37, 6, 9, 21, 64, 32, 9, 76};
    int size = sizeof(x)/sizeof(x[0]);

    BubbleSort(x, size);
    printArray(x, size);

    return 0;
}
