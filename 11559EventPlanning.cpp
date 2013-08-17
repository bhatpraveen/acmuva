/* 11559 Event Planning  http://uva.onlinejudge.org/external/115/11559.html */
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n, b, h, w, p, a, minb, hb;
    bool wa, wb; //weekly available, within budget flags

    while(scanf("%d %d %d %d", &n, &b, &h, &w) == 4) {
        minb = b+1;
        wb = false; //within budget?
        while(h--) {
            scanf("%d", &p);

            hb = p*n;
            if(hb <= b) wb = true;
            wa = false; //weekly available?

            for(int i = 0; i < w; ++i) {
                scanf("%d", &a);
                if(wb && !wa && a >= n) {
                    //Hotel can accommodate all this week
                    if(hb < minb) minb = hb;
                    wa = true;
                }
            } //for each week
        } //while still hotels to consider

        if(minb > b) printf("stay home\n");
        else printf("%d\n", minb);
    } //while test cases

    return 0;
}
