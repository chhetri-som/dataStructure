#include <stdio.h>

void shell_sort(int arr[], int size) {
    int gap = size / 2;

    while(gap > 0) {
        for(int i = gap; i < size; i++) {
            int anchor = arr[i];
            int j = i;

            while(j >= gap && arr[j - gap] > anchor) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = anchor;
        }

        gap = gap / 2;
    }
}

void print_array(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int tests[][20] = {
        {89, 78, 61, 53, 23, 21, 17, 12, 9, 7, 6, 2, 1},
        {},
        {1, 5, 8, 9},
        {234, 3, 1, 56, 34, 12, 9, 12, 1300},
        {5}
    };

    int sizes[] = {13, 0, 4, 9, 1};

    for(int i = 0; i < sizeof(sizes)/sizeof(sizes[0]); i++) {
        printf("Test case %d \n", i + 1);
        printf("Original array: ");
        print_array(tests[i], sizes[i]);

        shell_sort(tests[i], sizes[i]);
        printf("Sorted array: ");
        print_array(tests[i], sizes[i]);
        printf("\n");
    }

    return 0;
}
