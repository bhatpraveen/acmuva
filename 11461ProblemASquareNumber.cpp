/* UVa 11461 Problem A: Square Number */
#include <iostream>
#include <map>
#include <math.h>
using namespace std;

const int MAXSNROOT = sqrt(100000) + 1;
const int MAXSN = 100000;
int main() {
    int a, b;
    //int sn[MAXSN + 1];

    map<int, int> sn; //Greedy map of square numbers and the no. of square numbers upwards from 0

    int snCount = 1;
    int pow;
    int lastsn = 1;
    for(int i = 1; i <= MAXSNROOT; ++i) {
        pow = i * i;
        sn[pow] = snCount;
        //cout << "There are " << snCount << " SNs till " << pow << endl;
        for(int j = pow-1; j > lastsn; --j) {
            sn[j] = snCount - 1;
            //cout << "There are " << snCount << " SNs till " << j << endl;
        }
        ++snCount;
        lastsn = pow;
        //cout << lastsn << " ";
    }

    //for(int i = 1; i <= MAXSNROOT; ++i)
        //cout << sn[i] << " ";

    while(cin >> a >> b) {
        if(a <= 0 || b <= 0)
            return 0;
        //cout << sn[b] << "    "  << sn[a] << endl;
        int snCheck = sqrt(a);
        if((snCheck * snCheck) == a)
            cout << sn[b] - sn[a] + 1 << endl;
        else
            cout << sn[b] - sn[a] << endl;
    }

}
