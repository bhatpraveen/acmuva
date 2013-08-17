/* UVa 11799 Horror Dash http://uva.onlinejudge.org/external/117/11799.html */
#include <cstdio>
using namespace std;

int main() {
    int t, n, highest, speed;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i) {
        highest = 0;
        printf("Case %d: ", i);
        scanf("%d", &n);
        while (n--) {
            scanf("%d", &speed);
            if(speed > highest) highest = speed;
        }
        printf("%d\n", highest);
    }
    return 0;
}
