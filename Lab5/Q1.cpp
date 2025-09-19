#include <iostream>
using namespace std;


int refunc(int n){
    if ( n == 0 ) { 
        return 1 ;
    }

    return n * refunc(n-1);
}

int main(){
    int n;
    cout << "Enter any number:" << endl;
    cin >> n;
    int result;

    result = refunc(n);
    cout << "Result: " << result << endl;
}
