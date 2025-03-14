#include <stdio.h>
#include <stdlib.h>

void merge_two_sorted_list(int a[], int len_a, int b[], int len_b, int arr[]) {
    int i = 0, j = 0, k = 0;

    while(i < len_a && j < len_b) {
        if(a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < len_a) {
        arr[k] = a[i];
        i++;
        k++;
    }

    while (j < len_b) {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int n) {
    if(n <= 1) {
        return;
    }

    int mid = n / 2;

    int* left  = (int*)malloc(mid * sizeof(int));
    int* right = (int*)malloc((n - mid) * sizeof(int));

    for(int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for(int j = mid; j < n; j++) {
        right[j - mid] = arr[j];
    }

    merge_sort(left, mid);
    merge_sort(right, n - mid);

    merge_two_sorted_list(left, mid, right, n - mid, arr);

    free(left);
    free(right);

}

void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int test_cases[][20] = {
        {45, 76, 8, 44, 98, 0, 23, 12, 2, 54, 7, 5, 9, 5, 4, 76, 53, 32, 123, 5},
        {}, // Empty array
        {3}, // Single element array
        {9, 8, 7, 2, 5, 98, 4, 12},
        {1, 2, 3, 4, 5}
    };

    int sizes[] = {20, 0, 1, 8, 5}; // Sizes of the test arrays

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        printf("Test case %d:\n", i + 1);
        printf("Original array: ");
        print_array(test_cases[i], sizes[i]);

        merge_sort(test_cases[i], sizes[i]);

        printf("Sorted array: ");
        print_array(test_cases[i], sizes[i]);
        printf("\n");
    }
    return 0;
}
