#include <stdio.h>

void mergeSort(int arr[], int start, int last);
void merge(int arr[], int start, int mid, int last);

void mergeSort(int arr[], int start, int last) {
    if (start < last) {
        int mid = (start + last) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, last);

        merge(arr, start, mid, last);
    }
}

void merge(int arr[], int start, int mid, int last) {
    int n1 = mid - start + 1;   
    int n2 = last - mid;        
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++) left[i] = arr[start + i];
    for (int i = 0; i < n2; i++) right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }

    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {6, -25, 13542, 252,420, 11,654,56468,654,6578967};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Initial array: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Final array: "); 
    printArray(arr, n);

    return 0;
}
