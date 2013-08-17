/* UVa 11727 Cost Cutting http://uva.onlinejudge.org/external/117/11727.html */
#include <cstdio>
using namespace std;

int main() {
    int t, a, b, c;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i) {
        printf("Case %d: ", i);
        scanf("%d%d%d", &a, &b, &c);
        if((a >= b && a <= c) || (a <= b && a >= c)) printf("%d\n", a);
        else if((b >= a && b <= c) || (b <= a && b >= c)) printf("%d\n", b);
        else printf("%d\n", c);
    }
    return 0;
}
