#include <stdio.h>

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int min_index = i;

        for(int j = min_index + 1; j < size; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (i != min_index) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

void print_array(int arr[], int size){
    for(int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main() {
    int tests[][20] = {
        {89, 78, 61, 53, 23, 21, 17, 12, 9, 7, 6, 2, 1},
        {},
        {1, 5, 8, 9},
        {234, 3, 1, 56, 34, 12, 9, 12, 1300},
        {78, 12, 15, 8, 61, 53, 23, 27},
        {5}
    };

    int sizes[] = {13, 0, 4, 9, 8, 1};

    for(int i = 0; i < sizeof(sizes)/sizeof(sizes[0]); i++) {
        printf("Test case %d \n", i + 1);
        printf("Original array: ");
        print_array(tests[i], sizes[i]);

        selection_sort(tests[i], sizes[i]);
        printf("Sorted array: ");
        print_array(tests[i], sizes[i]);
        printf("\n");
    }

    return 0;
}
