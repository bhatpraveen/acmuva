/* 12571 - Brother & Sisters! */
#include <cstdio>
using namespace std;

int main() {
    int t, n, q, xi, a, anded;

    //map<int, int> x;
    int temp, max = 0;
    scanf("%d", &t);
    while(t--) {
        int x[256] = {};
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &xi);
            //temp = xi<<24; temp >>= 24;
            temp = 255 & xi;
            x[temp] = temp;
            //printf("%d\n", temp);
        }

        while(q--) {
            scanf("%d", &a);
            for(int i = 0; i < 256; ++i) {
                if(x[i]) {
                    //anded = lookup[a][x[i]];
                    anded = a & x[i];
                    //printf("%d & %d = %d ", a, x[i], anded);
                    if (anded > max) max = anded;
                }
            }
            printf("%d\n", max);
            max = 0;
        }
    }

    return 0;
}
