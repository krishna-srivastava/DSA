#include<iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    int n = end - start + 1;  
    int b[n];      
    int k = 0, i = start, j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            b[k] = arr[i];
            i++;
        } else {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = arr[i];
        i++;
        k++;
    }

    while (j <= end) {
        b[k] = arr[j];
        j++;
        k++;
    }

    for (int i = 0; i < n; i++) {
        arr[start + i] = b[i];
    }

    free(b);
}

void mergesort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;  
        mergesort(arr, start, mid);  
        mergesort(arr, mid + 1, end); 
        merge(arr, start, mid, end); 
    }
}

void printer(int *arr, int end) {
    for (int i = 0; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {3, 1, 64, 2, 8, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int start = 0;
    int end = size - 1;

    mergesort(arr, start, end);
    printer(arr, end);  

    return 0;
}
