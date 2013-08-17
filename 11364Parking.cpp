/* 11364 - Parking */
#include <iostream>
using namespace std;

int main() {
    int t, n, x;
    int smallest, largest;
    int distance = 0;

    cin >> t;
    while (t--) {
        cin >> n;
        cin >> x;
        if (n == 0)
            break;
        smallest = largest = x;
        while (--n) {
            cin >> x;
            smallest = x < smallest? x: smallest;
            largest = x > largest? x: largest;
            //cout << x << " " << smallest <<  " " << largest << endl;
        }
        cout << 2 * (largest - smallest) << endl;
    }

    return 0;
}
