/* UVa 11498  Division of Nlogonia http://uva.onlinejudge.org/external/114/11498.html */
#include <cstdio>
using namespace std;

int main() {
    int m, n, x, y, k;
    while(scanf("%d", &k) == 1) {
        if(k < 1) break;
        scanf("%d %d", &n, &m);
        while(k--) {
            scanf("%d %d", &x, &y);
            if(x == n || y == m) printf("divisa\n");
            else {
                printf("%c", y > m? 'N': 'S');
                printf("%c\n", x > n? 'E': 'O');
            }
        }
    }
    return 0;
}
