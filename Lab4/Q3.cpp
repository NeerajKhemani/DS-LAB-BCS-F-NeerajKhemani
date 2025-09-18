#include <iostream>
using namespace std;
int main(){
    int n; 
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[m]) m=j;
        }
        if(m!=i){
            int t=arr[i];
            arr[i]=arr[m];
            arr[m]=t;
        }
    }

    cout<<"Sorted: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
