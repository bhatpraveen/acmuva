/* UVa 483 Word Scramble http://uva.onlinejudge.org/external/4/483.html */
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char c;
    char s[1000]; //who knows what the word size is, let alone line!
    int i = 0;

    while((c = getchar()) != EOF) {
        if(c == ' ' || c == '\n') {
            for(int j = i-1; j >= 0; --j)
                printf("%c", s[j]);
            i = 0;
            printf("%c", c);
        }
        else s[i++] = c;
    }
    return 0;
}
