#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter sorted elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    int x;
    cout<<"Enter target: ";
    cin>>x;

    int l=0,h=n-1,pos,f=-1;
    while(l<=h && x>=arr[l] && x<=arr[h]){
        if(l==h){
            if(arr[l]==x) f=l;
            break;
        }
        pos=l+((x-arr[l])*(h-l))/(arr[h]-arr[l]);
        if(arr[pos]==x){ f=pos; break; }
        if(arr[pos]<x) l=pos+1;
        else h=pos-1;
    }

    if(f==-1) cout<<"Not found";
    else cout<<"Found at index "<<f;
}
