/* 591 - Box of Bricks */
#include <iostream>
using namespace std;

int main() {
    int n, h[100], k, sum, wh, setNo = 0;
    while(1) {
        cin >> n;
        if (n == 0)
            break;
        setNo++;
        k = 0; sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
            sum += h[i];
        }
        wh = sum / n; // wall height
        for (int i = 0; i < n; ++i) {
            if(h[i] > wh)
                k += h[i] - wh;
        }
        cout << "Set #" << setNo << endl;
        cout << "The minimum number of moves is " << k << "." << endl << endl;
    }
    return 0;
}
