#include<iostream>
using namespace std;

int binarysearch(int arr[],int size,int element){
    int low,mid,high;
    low=0;
    high=size-1;
    
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[]={2,6,9,14,24,45,79,86,88,94,99,101,200,300};
    int size=sizeof(arr)/sizeof(arr[0]);
    int element=101;
    int index=binarysearch(arr,size,element);

    cout<<"the element found at index: "<<index<<endl;
    return 0;
};