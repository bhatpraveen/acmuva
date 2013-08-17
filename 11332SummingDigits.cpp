/* 11332 - Summing Digits */
#include <iostream>
using namespace std;

inline int SumOfDigits(int n) {
    if (n < 10)
        return n;
    int sum = 0;
    while(n >= 1) {
        sum += n%10;
        n = n/10;
    }
    //cout << sum << endl;
    SumOfDigits(sum);
}


int main() {
    int n;
    int sum;
    while(1) {
        cin >> n;
        if(n == 0)
            break;
        //while(n > 9) {
            //cout << "n= " << " " << n << endl;
            n = SumOfDigits(n);
        //}
        cout << n << endl;
    }

    return 0;
}
