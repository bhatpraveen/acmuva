/* UVa 10137 The Trip: http://uva.onlinejudge.org/external/101/10137.html */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, avg, exchange, diff, expenses[1000] = {};
    float temp;
    char in[10];

    while(scanf("%d", &n) == 1) {
        avg = diff = exchange = 0;
        if(n < 1) return 0;
        for(int i = 0; i < n; ++i) {
            //scanf("%f", &temp);
            scanf("%s", in);
            cout << "in: " << in << endl;
            int digit = 0;
            while(in[digit] != '.') {
                cout << "dig: " << in[digit] << endl;
                expenses[i] = expenses[i] * 10 + (in[digit] - '0');
                cout << "exp: " << expenses[i] << endl;
                digit++;
            }

            expenses[i] = (int)(100*temp);
            avg += expenses[i];
        }
        avg = avg/n;
        //cout << "avg: " << avg << endl;
        sort(expenses, expenses + n);
        for(int i = 0; i < n; ++i) {
            diff = avg - expenses[i];
            //cout << "diff: " << diff << endl;
            if(diff <= 0) break;
            exchange += diff;
            //cout << "exchange: " << exchange << endl;
        }
        printf("%.2f\n", (float)exchange/100);
    }

    return 0;
}
