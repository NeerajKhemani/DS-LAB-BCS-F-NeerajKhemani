#include <iostream>
using namespace std;
int main(){
    int n; 
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=1;i<n;i++){
        int k=arr[i], j=i-1;
        while(j>=0 && arr[j]>k){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=k;
    }

    cout<<"Sorted: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    int x; 
    cout<<"Enter target: ";
    cin>>x;
    int l=0,h=n-1,mid,f=-1;
    while(l<=h){
        mid=(l+h)/2;
        if(arr[mid]==x){ f=mid; break; }
        else if(arr[mid]<x) l=mid+1;
        else h=mid-1;
    }

    if(f==-1) cout<<"Not found";
    else cout<<"Found at index "<<f;
}
