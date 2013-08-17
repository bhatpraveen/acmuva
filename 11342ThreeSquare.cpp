/* 11342 - Three-square */
#include <iostream>
#include <math.h>

using namespace std;


int main() {
    int n, num, a, b, c, rem;
    int sq[101];
    for (int i = 0; i < 101; ++i)
        sq[i] = i * i;

    cin >> n;
    while(n--) {
        cin >> num;
        rem = num;
        c = sqrt(rem);
        if (c * c == rem)
            a = b = 0;
        else {
            c = c - 1;
            rem = num - c * c;
            b = sqrt(rem);
            if (b * b == rem)
                a = 0;
            else {
                b = b -1;
                rem = rem - b * b;
                a = sqrt(rem);
            }
        }
        //if (a * a == rem)
            cout << a << " " << b << " " << c << endl;
        //else
          //  cout << -1 << endl;
    }

    return 0;
}
