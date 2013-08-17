/* UVa 402 M*A*S*H http://uva.onlinejudge.org/external/4/402.html */
#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main() {
    int n, lucky, stillLucky, deck[20], c = 0;
    vector<int> ppl;
    vector<int>::iterator it, it2;
    while(scanf("%d %d", &n, &lucky) == 2) {
        for (int i = 1; i <= n; ++i) ppl.push_back(i);

        stillLucky = n;
        printf("Selection #%d\n", ++c);
        it = ppl.begin();

        for (int i = 0; i < 20; ++i) {
            scanf("%d", &deck[i]);
            if (stillLucky <= lucky) continue;
            for(int j = deck[i] - 1; j < stillLucky && stillLucky > lucky; j += deck[i]) {
                ppl.erase(it + j);
                j--;
                stillLucky--;
            } //for eliminate
        } //for deck

        for (int j = 0; j < ppl.size(); ++j) {
            printf("%d", ppl[j]);
            stillLucky--;
            if(stillLucky) printf(" ");
            else printf("\n");
        } //for output
        ppl.clear();
        cout << endl;
    } //while n, lucky

    return 0;
}
