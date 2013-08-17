/* 299 - Train Swapping */
#include <iostream>
using namespace std;

int main() {
    int N, L, S;
    int train[51];

    cin >> N;

    while(N--) {
        cin >> L;
        S = 0;
        if(L == 0) {
            cout << "Optimal train swapping takes " << S << " swaps." << endl;
            continue;
        }
        for(int i = 1; i <= L; ++i)
            cin >> train[i];

        for(int i = 1; i <= L; ++i) {
            int j;
            for (j = i; train[j] != i; ++j)
                ;
            for(int k = j; k > i; --k) {
                int temp = train[k];
                train[k] = train[k - 1];
                train[k - 1] = temp;
                S++;
            }
        }
        cout << "Optimal train swapping takes " << S << " swaps." << endl;
    }

    return 0;
}
