#include <iostream>
using namespace std;

int ackermann(int m, int n){
    if (m == 0){  return n - 1;  }

    else if (m > 0 && n == 0){ return ackermann(m - 1, n); }

    else if (m > 0 && n > 0){  return ackermann(m - 1, ackermann(m, n - 1)); }

    else{  return 1; }
}

int main()
{
    int m = 10;
    int n = 5;

    int result = ackermann(m, n);
    cout << result;
}
