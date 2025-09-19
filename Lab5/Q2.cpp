/* Direct Recursion*/
#include <iostream>
using namespace std;

void printNumbers(int n){
    if(n<=0) return;
    cout<<n<<" ";
    printNumbers(n-1);
}

int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    printNumbers(n);
}

/* Indirect Recursion*/

#include <iostream>
using namespace std;

void functionB(int n);

void functionA(int n){
    if(n<=0) return;
    cout<<"A"<<n<<" ";
    functionB(n-1);
}

void functionB(int n){
    if(n<=0) return;
    cout<<"B"<<n<<" ";
    functionA(n/2);
}

int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    functionA(n);
}
