#include<iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int lb, int ub) {
    int pivot = arr[lb]; 
    int start = lb;
    int end = ub;

    while (start < end) {
        while (arr[start] <= pivot) { 
            start++;
        }
        while (arr[end] > pivot) {
            end--;
        }
        if (start < end) {
            swap(&arr[start], &arr[end]); 
        }
    }
    swap(&arr[lb], &arr[end]); 
    return end; 
}

void quicksort(int *arr, int lb, int ub) {
    if (lb < ub) {
        int loc = partition(arr, lb, ub); 
        quicksort(arr, lb, loc - 1); 
        quicksort(arr, loc + 1, ub); 
    }
}

void printer(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 8, 3, 6, 2, 5, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int lb = 0;
    int ub = n - 1;

    quicksort(arr, lb, ub);
    printer(arr, n); 
    return 0;
}
