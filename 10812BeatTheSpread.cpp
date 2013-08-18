/* UVa 10812 - Beat the Spread! http://uva.onlinejudge.org/external/108/10812.pdf */
#include <cstdio>
using namespace std;

int main() {
    int t, sum, diff, a, b, temp;
    bool poss;

    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &sum, &diff);
        poss = true;

        if(diff > sum || sum < 0 || diff < 0) poss = false;
        else {
            if((sum + diff) % 2 > 0) poss = false;
            a = (sum + diff) / 2;
            b = sum - a;
            if (a < 0 || b < 0) poss = false;
        }

        if(a < b) {
            temp - a;
            a = b;
            b = temp;
        }

        if(poss) printf("%d %d\n", a, b);
        else printf("impossible\n");
    }
    return 0;
}
