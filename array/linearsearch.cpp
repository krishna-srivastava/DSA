#include<iostream>
using namespace std;

int main(){
    int num;
    int arr[]={5,6,1,2,9,5,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    cout<<"enter a number to search: "<<endl;
    cin>>num;

    for(int i=0; i<n; i++){
        if(arr[i]==num){
            cout<<"element found at index: "<<i<<endl;
            return 0;
        }
    }

    cout<<"element not found........"<<endl;
    return 0;
};