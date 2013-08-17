/* UVa 11530 - SMS Typing http://uva.onlinejudge.org/external/115/11530.pdf */
#include <cstdio>
#include <string.h>
using namespace std;

int main() {
    int t, kp;
    char sms[102];
    char c;

    int presses['z'+1] = {};
    for (int i = 'a', j = 0; i <= 'r'; ++i, ++j) presses[i] = j%3 + 1;
    for (int i = 't', j = 0; i <= 'y'; ++i, ++j) presses[i] = j%3 + 1;
    presses['s'] = presses['z'] = 4;
    presses[' '] = 1;

    scanf("%d", &t); getchar();
    for(int i = 1; i <= t; ++i) {
        kp = 0;

        fgets(sms, 101, stdin);
        for(int j = 0; j < strlen(sms); ++j)
            kp += presses[sms[j]];

        printf("Case #%d: %d\n", i, kp);
    }

    return 0;
}
