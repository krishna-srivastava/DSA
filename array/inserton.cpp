#include<iostream>
using namespace std;

int main(){
    int size,i,num,position,arr[100];
    printf("enter the size of array: ");
    cin>>size;

    cout<<"enter the element in the array: "<<endl;
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<endl;

    cout<<"enter the element to insert in the array: "<<endl;
    cin>>num;
    cout<<"enter the postion (0-based index)"<<endl;
    cin>>position;

    cout<<"the array before insertion:"<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=size; i>position; i--){
        arr[i]=arr[i-1];
    }
    arr[position]=num;
    size++;

    cout<<"the array after insertion:"<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
};