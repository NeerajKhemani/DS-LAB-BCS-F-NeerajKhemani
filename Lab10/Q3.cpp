#include <iostream>
#include <vector>
using namespace std;

int kthLargest(vector<int> a,int k){
    
    int n=a.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j] > a[i]){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    return a[k-1];
}

int main(){

    vector<int> x = {1,23,12,9,30,2,50};
    int k = 3;

    cout<<kthLargest(x,k)<<endl;

    vector<int> y = {12,3,5,7,19};
    cout<<kthLargest(y,2)<<endl;

    return 0;
}
