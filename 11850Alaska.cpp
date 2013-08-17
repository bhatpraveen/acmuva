/* 11850 - Alaska */
#include <iostream>
#include <algorithm>
using namespace std;

const int total = 1422;
const int mileage = 200;

int main() {
    int fillingstation[total + 1];
    int n;
    bool possible = true;

    while(1) {
        cin >> n;
        if (n == 0)
            return 0;

        for (int i = 0; i < n; ++i)
            cin >> fillingstation[i];

        if (n <= total/mileage) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        sort(fillingstation, fillingstation + n);

        for (int i = 1; i < n; ++i) {
            if ((fillingstation[i] - fillingstation[i - 1]) > mileage) {
                possible = false;
                break;
            }
        }

        if ((2 * (total - fillingstation[n - 1]) ) > mileage)
            possible = false;

        if (possible) cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;

        possible = true;
    }

    return 0;
}
