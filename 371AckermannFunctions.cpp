/* 371 Ackermann Functions */
#include <iostream>
using namespace std;

int GetSeqLen(long long int n, int i) {
    if (n == 1) return i;
    i++;
    if (n % 2) GetSeqLen(3 * n + 1, i);
    else GetSeqLen(n / 2, i);
}

int main() {
    long long int n, L, H, V;
    int S, seqlen;
    while (cin >> L >> H) {
        if (L == 0 && H == 0)
            return 0;
        S = 0;
        V = 0;
        if (L > H) {
            long long int temp = L;
            L = H;
            H = temp;
        }
        if (L == 1) {
            S = 3;
            V = 1;
        }
        for (long long int n = L; n <= H; ++n) {

            seqlen = GetSeqLen(n, 0);
            if (seqlen > S) {
                S = seqlen;
                V = n;
            }
        }
        cout << "Between " << L << " and " << H << ", " << V << " generates the longest sequence of " << S << " values." << endl;
    }

    return 0;
}
