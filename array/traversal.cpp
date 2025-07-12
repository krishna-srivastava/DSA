#include<iostream>
using namespace std;

int main(){
    int size,i;
    printf("enter the size of array: ");
    cin>>size;
    
    int arr[size]; 

    cout<<"enter the element in the array: "<<endl;
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<endl;

    cout<<"value stored in array are: "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
};