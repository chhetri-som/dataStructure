#include <stdio.h>

void insertion_sort(int elements[], int n) {
    for(int i = 1; i < n; i++) {
        int anchor = elements[i];
        int j = i - 1;

        while (j >= 0 && anchor < elements[j]) {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = anchor;
    }
}

void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int elements[] = {45, 76, 43, 1, 87, 9, 4, 55, 7, 6, 32, 87, 46, 43};
    int n = sizeof(elements)/sizeof(elements[0]);

    printf("Original array: ");
    print_array(elements, n);

    insertion_sort(elements, n);

    printf("Sorted array: ");
    print_array(elements, n);

    int tests[][10] = {
        {11, 9, 29, 7, 2, 15, 28},
        {3, 7, 9, 11},
        {25, 22, 21, 10},
        {29, 15, 28},
        {0}, // Empty array (size 0)
        {6}  // Single element array
    };

    int sizes[] = {7, 4, 4, 3, 0, 1}; // Sizes of the test arrays

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        printf("\nTest case %d:\n", i + 1);
        printf("Original array: ");
        print_array(tests[i], sizes[i]);

        insertion_sort(tests[i], sizes[i]);

        printf("Sorted array: ");
        print_array(tests[i], sizes[i]);
    }

    return 0;
}
