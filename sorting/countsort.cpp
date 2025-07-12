#include<iostream>
using namespace std;

int findmax(int *arr, int n){
    int max=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

void countsort(int *arr, int n){
    int max=findmax(arr,n);
    int *count=(int*)calloc(max+1,sizeof(int));

    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }

    int index=0;
    for(int i=0; i<max; i++){
        while(count[i]>0){
            arr[index++]=i;
            count[i]--;
        }
    }
}

void printer(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[]={2,4,1,5,3,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    printer(arr,n);
    countsort(arr,n);
    printer(arr,n);

    return 0;
};