/* UVa 100 - The 3n + 1 problem http://uva.onlinejudge.org/external/1/100.html */
#include <cstdio>
using namespace std;

long long int cache[1000000] = {};

int main() {
    long long int i, j, n, low, high, cycle, highest;

    while(scanf("%lld %lld", &i, &j) == 2) {
        if(i > j) {
            low = j; high = i;
        }
        else {
            low = i; high = j;
        }
        highest = 0;

        /*
        Tried filling the entire cache before processing the first input,
        which helps knock off the comparison with cache below, but it does
        a worse runtime! The reason is most likely because the input doesn't
        contain the entire range. Maybe, the upper limit mentioned has a
        typo, since surely n=999999 crosses the int boundary!
        */
        for(int m = low; m <= high; ++m) {
            if(cache[m] == 0) {
                n = m; cycle = 1;
                while(n > 1) {
                    if(n&1) n = 3*n+1;
                    else n >>= 1;
                    cycle++;
                }
                cache[m] = cycle;
            }
            else cycle = cache[m];


            if(cycle > highest) highest = cycle;
        }
        printf("%lld %lld %lld\n", i, j, highest);
    }
    return 0;
}
