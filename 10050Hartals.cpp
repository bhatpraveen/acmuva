/* 10050 - Hartals */
#include <iostream>
using namespace std;

int main() {
    int t, n, p, h[101], hartals = 0;
    const int holiday1 = 6; //Fri holiday
    const int holiday2 = 7; //Sat holiday

    cin >> t;

    while(t--) {
        cin >> n >> p;

        for(int i = 1; i <= p; ++i) cin >> h[i];

        for(int day = 1; day <= n; ++day) {
            if (day % ((day/7) * 7 + holiday1) == 0 || (day % holiday2) == 0)  continue; //skip counting holiday hartals
            for(int i = 1; i <= p; ++i) {
                if (day % h[i] == 0) {
                    //cout << "hartal on day " << day << " due to " << h[i] << endl;
                    hartals++;
                    break; //don't consider any other hartal that falls on the same day;
                }
            }
            //cout << "day: " << day << " " << hartals << endl;
        }
        cout << hartals << endl;
        hartals = 0;
    }
    return 0;
}
