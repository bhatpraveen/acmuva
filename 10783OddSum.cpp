/* UVa 10783 - Odd Sum */
#include <iostream>
using namespace std;

int main() {
    int T, a, b;
    int oddSum = 0;

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> a >> b;
        oddSum = 0;
        for (int j = a&1? a: a+1; j <= b; j += 2)
            oddSum += j;
        cout << "Case " << i + 1 << ": " << oddSum << endl;
    }

    return 0;
}
