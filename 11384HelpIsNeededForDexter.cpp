/* 11384 - Help is needed for Dexter */
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int N, L;
    while (cin >> N) {
        //cout << (int)(log(N)/log(2)) + 1 << endl;
        cout << (int)log2(N) + 1 << endl;
    }

    return 0;
}
