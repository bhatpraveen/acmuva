#include <iostream>
#include <stack>
using namespace std;

int main() {
    int coaches[1000];
    stack<int> station;

    int N, coach;
    bool marshallable;

    while(cin >> N) {
        if (N < 1)
            return 0;
        while(1) {
            cin >> coaches[0];
            if (coaches[0] < 1) {
                cout << endl;
                break; // Process next train
            }

            coach = 1;
            station = stack<int>(); //clear the station for next train coaches
            marshallable = true;

            for (int i = 1; i < N; ++i)
                cin >> coaches[i];

            for (int i = 0; i < N; ++i) {
                if (coaches[i] >= coach && coaches[i] <= N) {
                    //Coach needed at B is at still at A
                    //cout << "DEBUG: Coaches[i], coach: " << coaches[i] << " " << coach << endl;
                    while(coach < coaches[i]) {
                        //Remove coach from A and push it into the station
                        station.push(coach);
                        //cout << "DEBUG: Pushing coach " << coach << " to station" << endl;
                        ++coach;
                    }
                    ++coach; //Equivalent to pushing coach onto station and popping it back to B
                    //cout << "DEBUG: Marshalled coach " << coach - 1 << " from A" << endl;
                }
                else {
                    //Coach already at station
                    if(station.empty() || station.top() != coaches[i]) {
                        //Cannot marshall the coaches in required order
                        marshallable = false;
                        break;
                    }
                    else {
                        //Pop the coach at station to B
                        //cout << "DEBUG: Marshalled coach " << station.top() << " from station" << endl;
                        station.pop();
                    }
                }
            }
            if (marshallable) cout << "Yes" << endl;
            else cout << "No" << endl;
        } //while 1
    } //while N

    return 0;
}
