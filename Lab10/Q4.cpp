#include <iostream>
#include <vector>
using namespace std;

void heapifyMax(vector<int> &a,int i,int n){
    
    int l = 2*i+1 , r = l+1 , mx=i;

    if(l<n && a[l] > a[mx]) mx=l;
    if(r<n && a[r] > a[mx]) mx=r;

    if(mx!=i){
        int t=a[i]; a[i]=a[mx]; a[mx]=t;
        heapifyMax(a,mx,n);
    }
}

void convertMinToMax(vector<int> &arr){
    
    int n = arr.size();

    for(int i = n/2 - 1; i>=0; i--){
        heapifyMax(arr,i,n);
    }
}

int main(){

    vector<int> arr = {3,5,9,6,8,20,10,12,18,9};

    convertMinToMax(arr);

    for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
