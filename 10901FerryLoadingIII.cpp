/* 10901 - Ferry Loading III */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Order {
    int t; //time of arrival or car
    int o; //order in input
};

int main(){
    int c, n, t, m, arrival, currtime;
    string bank;

    vector<Order> left, right;
    int inputOrder[10001];
    cin >> c;

    while(c--) {
        cin >> n >> t >> m;

        for(int i = 0; i < m; ++i) {
            cin >> arrival >> bank;
            Order car;
            car.t = arrival;
            car.o = i;

            if (!bank.compare("left")) {
                left.push_back(car);
            }
            else {
                right.push_back(car);
            }
        }

        currtime = 0;
        for(int i = 0, li = 0, ri = 0; i < m; ) {
            //cout << "Cars ferried so far: " << i << endl;
            //Ferry at left bank
            int cars = 0;
            bool crossFerry = false;

            while(li < left.size()) {
                //cout << "value of li & i: " << li << " & " << i << endl;
                if (currtime < left[li].t) {
                    //No cars on left bank yet
                    if (cars > 0) {
                        crossFerry = true; //Don't wait for other cars
                        break;
                    }
                    //no cars at left bank & none on ferry
                    //cout << "no cars at left bank & none on ferry" << endl;
                    if (ri >= right.size() || (left[li].t <= right[ri].t && cars < n)) {
                        //Car arrived at left earlier than right
                        //cout << "Car arrived at left earlier than right" << endl;
                        currtime = left[li].t; //Ferry waits till car's arrival
                        cars++;
                        inputOrder[left[li].o] = currtime + t;

                        //cout << "loading left car " << li << " that arrived at " << left[li].t << " & order " << left[li].o << endl;
                        //cout << "current time" << currtime << endl;
                        //cout << "reaching time" << inputOrder[left[li].o] << endl;

                        li++;
                        i++;
                        //crossFerry = true;
                    }
                    else {
                        //Car arrived at right before left, cross empty ferry
                        if (currtime < right[ri].t)
                            currtime = right[ri].t; //Wait till car arrives at right, then cross over
                        //cout << "Choosing to pick up right bank car, none on left yet" << endl;
                        crossFerry = true;
                    }
                }
                else {
                    cars++;
                    inputOrder[left[li].o] = currtime + t;

                    //cout << "loading left car " << li << " that arrived at " << left[li].t << " & order " << left[li].o << endl;
                    //cout << "current time" << currtime << endl;
                    //cout << "reaching time" << inputOrder[left[li].o] << endl;

                    crossFerry = true;
                    li++;
                    i++;
                }

               if (cars > 0 && cars <= n) {
                    crossFerry = true;
                    if (cars == n)
                        break;
                }
                else {
                    break;
                }
            }

            //cout << "ri= " << ri << endl;
            if (crossFerry || ri < right.size()) {
                if (!crossFerry && currtime < right[ri].t)
                    currtime = right[ri].t; //needed when all cars at left have been ferried
                currtime += t;
                //cout << "current time" << currtime << endl;
                //cout << "crossing ferry to right with " << cars << " cars " << endl;
                //cout << "reaching time " << currtime << endl;
            }
            else break;


            //Ferry at right bank
            cars = 0;
            crossFerry = false;

            while(ri < right.size()) {
                //cout << "value of ri & i: " << ri << " & " << i << endl;
                if (currtime < right[ri].t) {
                    //No cars on right bank yet
                    if (cars > 0) {
                        crossFerry = true; //Don't wait for other cars
                        break;
                    }
                    //no cars at right bank & none on ferry
                    //cout << "no cars at right bank & none on ferry" << endl;
                    if (li >= left.size() || (right[ri].t <= left[li].t && cars < n)) {
                        //Car arrived at left later than right
                        //cout << "Car arrived at left later than right" << endl;
                        currtime = right[ri].t; //Ferry waits till car's arrival
                        cars++;
                        inputOrder[right[ri].o] = currtime + t;

                        //cout << "loading right car " << ri << " that arrived at " << right[ri].t << " & order " << right[ri].o << endl;
                        //cout << "current time" << currtime << endl;
                        //cout << "reaching time" << inputOrder[right[ri].o] << endl;

                        ri++;
                        i++;
                        //crossFerry = true;
                    }
                    else {
                        //Car arrived at left before right, cross empty ferry
                        if (currtime < left[li].t)
                            currtime = left[li].t; //Wait till car arrives at left, then cross over
                        //cout << "Choosing to pick up left bank car, none on right yet" << endl;
                        crossFerry = true;
                    }
                }
                else {
                    cars++;
                    inputOrder[right[ri].o] = currtime + t;

                    //cout << "loading right car " << ri << " that arrived at " << right[ri].t << " & order " << right[ri].o << endl;
                    //cout << "current time" << currtime << endl;
                    //cout << "reaching time" << inputOrder[right[ri].o] << endl;

                    crossFerry = true;
                    ri++;
                    i++;
                }

               if (cars > 0 && cars <= n) {
                    crossFerry = true;
                    if (cars == n)
                        break;
                }
                else {
                    break;
                }
            }

            //cout << "li= " << li << endl;

            if (crossFerry || li < left.size()) {
                if (!crossFerry && currtime < left[li].t)
                    currtime = left[li].t; //needed when all cars at right have been ferried
                currtime += t;
                //cout << "current time" << currtime << endl;
                //cout << "crossing ferry to left with " << cars << " cars " << endl;
                //cout << "reaching time " << currtime << endl;
            }
            else break;

            crossFerry = false;

        //    cout << "i= " << i << endl;
        }

        for (int i = 0; i < m; ++i)
            cout << inputOrder[i] << endl;
        if (c > 0) cout << endl;
        left.clear();
        right.clear();
    }

    return 0;
}
