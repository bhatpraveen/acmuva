/* 12004 Bubble Sort */
#include <iostream>

using namespace std;

int main() {
    long long int count = 0, n;
    int T, i, j, temp,arr[100000];
    cin >> T;
    for (int c = 1; c <= T; ++c) {
        cin >> n;
        cout << "Case " << c << ": ";

        //Min 0 swaps, max n swaps
        //If run infinite times with random spread, total swaps would be sum(1:n)
        count = n * (n - 1) / 2; //total swaps

        //Average swap falls midway of sum
        if (count % 2 == 0) cout << count / 2;
        else cout << count << "/" << 2;
        cout << endl;
    }
    return 0;
}
