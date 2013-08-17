/* UVa 11044 - Searching for Nessy http://uva.onlinejudge.org/external/110/11044.pdf */
#include <cstdio>
using namespace std;

int main() {
    int t, m, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);

        n -= 2;
        m -= 2;
        n = n%3? n/3 + 1: n/3;
        m = m%3? m/3 + 1: m/3;

        printf("%d\n", n*m);

        /*
        The above lines can be replaced by one below, but the runtime of above is 0.003s better!
        Perhaps, if statement can do better than ternary operator too, haven't checked.

        printf("%d\n", ((n-2)%3? (n-2)/3 + 1: (n-2)/3) * (m = (m-2)%3? (m-2)/3 + 1: (m-2)/3));
        */
    }

    return 0;
}
