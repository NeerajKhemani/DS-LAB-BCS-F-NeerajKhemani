#include <iostream>
using namespace std;
int main(){
    int n; 
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    int gap=n;
    bool sw=true;
    int comps=0, swaps=0;
    while(gap>1 || sw){
        gap=(gap*10)/13;
        if(gap<1) gap=1;
        sw=false;
        for(int i=0;i+gap<n;i++){
            comps++;
            if(arr[i]>arr[i+gap]){
                int t=arr[i];
                arr[i]=arr[i+gap];
                arr[i+gap]=t;
                swaps++;
                sw=true;
            }
        }
    }

    cout<<"Sorted: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Comparisons: "<<comps<<endl;
    cout<<"Swaps: "<<swaps;
}
