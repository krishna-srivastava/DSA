#include<iostream>
using namespace std;

void printer(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void selectionsort(int *a, int n){
    for(int i=0; i<n-1; i++){
        int min=i;
        for(int j=i+1; j<n; j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(min != i){
            int temp=a[min];
            a[min]=a[i];
            a[i]=temp;
        }
    }
}

int main(){
    int arr[]={2,5,3,1,8,4};  
    int n=6;
    selectionsort(arr,n);
    printer(arr,n);
    return 0;
};