/* Tail Recursion*/
#include <iostream>
using namespace std;

int sumTail(int n, int total){
    if(n==0) return total;
    return sumTail(n-1, total+n);
}

int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    cout<<"Sum using tail recursion: "<<sumTail(n,0)<<endl;
}


/* Non-Tail Recursion */

#include <iostream>
using namespace std;

int sumNonTail(int n){
    if(n==0) return 0;
    return n + sumNonTail(n-1);
}

int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    cout<<"Sum using non-tail recursion: "<<sumNonTail(n)<<endl;
}
