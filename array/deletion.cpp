#include<iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};
    int n=5,del;

    cout<<"currently array: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"enter the element you want to delete: "<<endl;
    cin>>del;

    int i=0;
    for(i=0; i<n; i++){
        if(arr[i]==del){
            break;
        }
    }

    if(i<n){
        for(int j=i; j<n-1; j++){
            arr[j]=arr[j+1];
        }
        n--;
        cout<<"array after deletion: "<<endl;
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }else{
        cout<<"element not found........."<<endl;
    }

    return 0;
};