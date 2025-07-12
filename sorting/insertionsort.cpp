#include<iostream>
using namespace std;

void printer(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionsort(int *arr, int n){
    for(int i=1; i<n; i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

int main(){
    int arr[]={2,4,1,5,3,8};
    int n=6;
    insertionsort(arr,n);
    printer(arr,n);
    return 0;
};