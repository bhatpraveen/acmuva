/* 11371 - Number Theory for Newbies */
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

inline long long int GetPower(int base, int n) {
    long long int power = 1;
    for (int i = 0; i < n; i ++)
        power *= base;
    return power;
}

int main() {
    long long int a, b;
    int n, nDigits, digit[10];

    while(cin >> n) {
        for (nDigits = 0; n > 0; ++nDigits) {
            digit[nDigits] = n % 10;
            n = n / 10;
        }
        //cout << nDigits << endl;

        sort(digit, digit + nDigits);

        a = 0;
        for (int i = nDigits - 1; i >= 0; --i) {
            a += digit[i] * GetPower(10, i);
        }
        //cout << a << endl;

        b = 0;
        int k = 0;
        if(digit[0] == 0) {
            for(k = 0; digit[k] == 0; ++k)
                ;
            //cout << k << " " << digit[k] << endl;
            int temp = digit[k];
            digit[k] = digit[0];
            digit[0] = temp;
        }

        for (int i = 0; i < nDigits; ++i) {
            b += digit[nDigits - i - 1] * GetPower(10, i);
        }
        //cout << b << endl;

        cout << a << " - " << b << " = " << a - b << " = " << 9 << " * " << (a - b)/ 9 << endl;
    }

    return 0;
}
