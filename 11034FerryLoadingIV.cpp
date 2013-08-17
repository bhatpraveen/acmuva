/* 11034: Ferry Loading IV */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int c, ferrylen, cars, carlen;
    string bank;
    vector<int> left, right;

    cin >> c;
    while(c--) {
        cin >> ferrylen >> cars;
        ferrylen *= 100;

        for(int i = 0; i < cars; ++i) {
            cin >> carlen >> bank;
            if (!bank.compare("left")) left.push_back(carlen);
            else right.push_back(carlen);
        }

        int trips = 0;
        int triplen = 0;

        for(int i = 0, li = 0, ri = 0; i < cars; ) {
            //cout << "Cars ferried so far: " << i << endl;
            //Ferry at left bank
            triplen = 0;
            while(li < left.size()) {
                triplen += left[li];
                //cout << "Loading " << i << " car at left: " << li << " " << left[li] << " " << triplen << endl;
                if (triplen <= ferrylen) {
                    li++;
                    i++;
                }
                else {
                    //left bank empty
                    break;
                }
            }
            if(triplen > 0 || ri < right.size()) //send half-full or empty ferry
                trips++;
            else break;

            //cout << "Trip #" << trips << endl;

            triplen = 0;

            //Ferry at right bank
            while(ri < right.size()) {
                triplen += right[ri];
                //cout << "Loading " << i << " car at right: " << ri << " " << right[ri] << " " << triplen << endl;
                if (triplen <= ferrylen) {
                    ri++;
                    i++;
                }
                else {
                    //left bank empty
                    break;
                }
            }
            if(triplen > 0 || li < left.size()) //send half-full or empty ferry
                trips++;
            else break;

            //cout << "Trip #" << trips << endl;
        }

        cout << trips << endl;
        left.clear();
        right.clear();
    }

    return 0;
}
