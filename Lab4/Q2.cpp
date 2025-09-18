#include <iostream>
using namespace std;
int main(){
    int n; 
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<"Unsorted: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }

    cout<<"Sorted: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
