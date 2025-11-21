#include <iostream>
#include <string>
using namespace std;

struct Runner{
    string n;
    int t;
};

void mergeRun(Runner a[],int l,int m,int r){

    int n1=m-l+1;
    int n2=r-m;

    Runner *L=new Runner[n1], *R=new Runner[n2];

    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int j=0;j<n2;j++) R[j]=a[m+1+j];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2){
        if(L[i].t <= R[j].t){
            a[k]=L[i]; i++;
        } else{
            a[k]=R[j]; j++;
        }
        k++;
    }

    while(i<n1){ a[k]=L[i]; i++; k++; }
    while(j<n2){ a[k]=R[j]; j++; k++; }

    delete[] L;
    delete[] R;
}

void mergeSort(Runner a[],int l,int r){
    if(l>=r) return;
    int m=(l+r)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    mergeRun(a,l,m,r);
}

int main(){

    Runner arr[10];

    for(int i=0;i<10;i++){
        cout<<"Enter name and finish time for runner "<<i+1<<": ";
        cin>>arr[i].n>>arr[i].t;
    }

    mergeSort(arr,0,9);

    cout<<"\nTop 5 fastest runners:\n";
    for(int i=0;i<5;i++){
        cout<<i+1<<". "<<arr[i].n<<" - "<<arr[i].t<<" seconds\n";
    }

    return 0;
}
