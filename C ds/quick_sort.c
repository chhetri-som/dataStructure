#include <stdio.h>

void swap(int* a, int* b) {
    if(*a != *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int partition(int elements[], int start, int end) {
    int pivot_index = start;
    int pivot = elements[pivot_index];

    while(start < end) {
        while(start < end && elements[start] <= pivot) {
            start++;
        }

        while(elements[end] > pivot) {
            end--;
        }

        if(start < end) {
            swap(&elements[start], &elements[end]);
        }
    }

    swap(&elements[pivot_index], &elements[end]);
    return end;
}

void quick_sort(int elements[], int start, int end) {
    if(start < end) {
        int pi = partition(elements, start, end);

        quick_sort(elements, start, pi - 1);
        quick_sort(elements, pi + 1, end);
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
    int elements[] = {11, 9, 29, 7, 2, 15, 28, 2, 7, 99, 14, 75};
    int n = sizeof(elements) / sizeof(elements[0]);

    printf("Original array: ");
    print_array(elements, n);

    quick_sort(elements, 0, n - 1);

    printf("Sorted array: ");
    print_array(elements, n);

    int tests[][10] = {
        {11, 9, 29, 7, 2, 15, 28},
        {3, 7, 9, 11},
        {25, 22, 21, 10},
        {29, 15, 28},
        {0},
        {6}
    };

    int sizes[] = {7, 4, 4, 3, 0, 1};

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        printf("\nTest case %d:\n", i + 1);
        printf("Original array: ");
        print_array(tests[i], sizes[i]);

        quick_sort(tests[i], 0, sizes[i] - 1);

        printf("Sorted array: ");
        print_array(tests[i], sizes[i]);
    }
    return 0;
}
