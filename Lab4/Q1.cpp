#include <iostream>
using namespace std;
int main(){
    int n; 
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    int x; 
    cout<<"Enter target: ";
    cin>>x;
    int pos=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==x){ pos=i; break; }
    }
    if(pos==-1) cout<<"Not found";
    else cout<<"Found at index "<<pos;
}
