/* UVa 11340 - Newspaper */

#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

const int LINESIZE = 10001;

int main() {
    int N, K, M;
    unsigned long long int amount;
    char c;
    char line[LINESIZE + 1];
    int rate;
    map<char, int> rateTable;

    cin >> N;
    while(N--) {
        cin >> K;
        while (K--) {
            cin >> c >> rate;
            rateTable[c] = rate;
        }
        amount = 0;
        cin >> M;
        cin.ignore();
        while(M > 0) {
            //cin.get(c);
            c = getchar();
            if(c == '\n' || c == EOF) M--;
            amount += rateTable[c];
        }
        printf("%4.2f%c\n", (double)amount/100.0, '$');
        rateTable.clear();
    }

    return 0;
}
