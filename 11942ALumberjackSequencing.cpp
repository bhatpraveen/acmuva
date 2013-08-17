/* UVa  11942 A: Lumberjack Sequencing */
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main() {
    int N;
    bool ordered = true;
    int beardLen, prevBeardLen;
    enum ORDER {UNSET, ASCENDING, DESCENDING};
    ORDER eORDER = UNSET;

    cin >> N;
    cout << "Lumberjacks:" << endl;

    while (N--) {
        ordered = true;
        prevBeardLen = -1; //1st beard, has no prev
        eORDER = UNSET;

        for (int lumberjacks = 1; lumberjacks <= 10; ++lumberjacks) {
            cin >> beardLen;
            if (lumberjacks > 2 && eORDER == ASCENDING) {
                if (prevBeardLen > beardLen) {
                    ordered = false;
                    //break;
                }
            }
            else if (lumberjacks > 2 && eORDER == DESCENDING) {
                if (prevBeardLen < beardLen) {
                    ordered = false;
                    //break;
                }
            }
            //Order unset or equal
            if (lumberjacks > 1 && eORDER == UNSET) {
                if (prevBeardLen > beardLen) {
                    eORDER = DESCENDING;
                }
                else if (prevBeardLen < beardLen) {
                    eORDER = ASCENDING;
                }

            }
            prevBeardLen = beardLen;
        } //while not EOL
        if(ordered) cout << "Ordered" << endl;
        else cout << "Unordered" << endl;
    } //while N--

    return 0;
}
