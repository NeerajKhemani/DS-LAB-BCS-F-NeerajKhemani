#include <iostream>
#include <vector>
using namespace std;

int isHeapArr(vector<int> a){
    
    int n=a.size();
    for(int i=0;i<n/2;i++){
        int l=2*i+1 , r=2*i+2;
        if(l<n && a[i] > a[l]) return 0;
        if(r<n && a[i] > a[r]) return 0;
    }
    return 1;
}

void sortAsc(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[i]){
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
    }
}

int main(){

    vector<int> arr = {4,5,6,7,8};  

    cout<<isHeapArr(arr)<<endl;

    sortAsc(arr);

    for(int k=0;k<arr.size();k++) cout<<arr[k]<<" ";
    cout<<endl;

    return 0;
}
