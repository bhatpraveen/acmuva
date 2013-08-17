/* UVa 128 - Software CRC (redoing it since old runtime exceeds 1sec) http://uva.onlinejudge.org/external/1/128.pdf */
#include <cstdio>
#include <string.h>
using namespace std;

static const int G = 34943; //0x887f

int main() {
    char m[1025];
    unsigned int crc, rem;

    while(fgets(m, 1025, stdin)) {
        if(m[0] == '#') break; //The input is terminated by a line that contains a # in column 1.

        /*
        Between the multiplication and shift operations, there's only an improvement of
        0.004s! Looks like the compiler optimizes it well.
        */

        rem = 0;
        for(int i = 0; m[i] != '\n'; ++i)
            rem = ((rem << 8) + m[i]) % G; //rem = ((rem * 256) + m[i]) % G;

        crc = (G - (rem << 16) % G) % G; //crc = (G - (rem *256 *256) % G) % G;

        printf("%02X %02X\n", crc >> 8, crc & 0xff);
    }

    return 0;
}
