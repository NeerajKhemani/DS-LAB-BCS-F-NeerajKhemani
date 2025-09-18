#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void bubble(int a[],int n,int &cmp,int &sw){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            cmp++;
            if(a[j]>a[j+1]){
                int t=a[j];a[j]=a[j+1];a[j+1]=t;
                sw++;
            }
        }
    }
}

void insertion(int a[],int n,int &cmp,int &sw){
    for(int i=1;i<n;i++){
        int k=a[i],j=i-1;
        while(j>=0){ cmp++;
            if(a[j]>k){ a[j+1]=a[j]; j--; sw++; }
            else break;
        }
        a[j+1]=k;
    }
}

void shell(int a[],int n,int &cmp,int &sw){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int k=a[i],j=i;
            while(j>=gap){ cmp++;
                if(a[j-gap]>k){ a[j]=a[j-gap]; j-=gap; sw++; }
                else break;
            }
            a[j]=k;
        }
    }
}

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    int *a1=new int[n],*a2=new int[n],*a3=new int[n];
    for(int i=0;i<n;i++){a1[i]=arr[i];a2[i]=arr[i];a3[i]=arr[i];}

    int c1=0,s1=0,c2=0,s2=0,c3=0,s3=0;

    auto t1=high_resolution_clock::now();
    bubble(a1,n,c1,s1);
    auto t2=high_resolution_clock::now();
    auto d1=duration_cast<milliseconds>(t2-t1).count();

    auto t3=high_resolution_clock::now();
    insertion(a2,n,c2,s2);
    auto t4=high_resolution_clock::now();
    auto d2=duration_cast<milliseconds>(t4-t3).count();

    auto t5=high_resolution_clock::now();
    shell(a3,n,c3,s3);
    auto t6=high_resolution_clock::now();
    auto d3=duration_cast<milliseconds>(t6-t5).count();

    cout<<"Bubble Sort -> Time: "<<d1<<"ms Comparisons: "<<c1<<" Swaps: "<<s1<<endl;
    cout<<"Insertion Sort -> Time: "<<d2<<"ms Comparisons: "<<c2<<" Swaps: "<<s2<<endl;
    cout<<"Shell Sort -> Time: "<<d3<<"ms Comparisons: "<<c3<<" Swaps: "<<s3<<endl;
}
