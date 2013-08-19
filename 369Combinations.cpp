/* UVa 369 - Combinations http://uva.onlinejudge.org/external/3/369.pdf */
#include <cstdio>
#include <vector>
#include <string.h>
//#include <iostream>
using namespace std;

#define LL unsigned long long int
static const int MAX = 10240; //who knows how many leading spaces will be there
static LL pt[101][101] = {};

static inline void PascalsTriangle(int n) {
    int rows = n; //no of rows to print
    int j1;

    pt[0][0] = 1;
    pt[1][0] = 1;
    pt[1][1] = 1;

    //cout << 1 << endl; cout << 1 << " " << 1 << endl;
    for(int i = 2; i <= rows; ++i) {
        //cout << i << ":";
        pt[i][0] = 1;
        //cout << 1 << " ";
        int j = 1;
        for(; j <= i/2; ++j) {
            pt[i][j] = pt[i-1][j-1] + pt[i-1][j];
            //cout << "(" << i << ":" << j << ")";
            //cout << pt[n1][j] << " ";
        }
        j1 = i&1? i/2: i/2 - 1;
        for(; j1 > 0; j++) {
            pt[i][j] = pt[i][j1--];
            //cout << "(" << i << ":" << j << ")";
            //cout << pt[n1][j] << " ";
        }
        pt[i][i] = 1;
        //cout << 1 << endl;
    }
}

inline long long int GetNumber(char s[], int *index) {
    long long int x;
    int i = *index;
    int len = strlen(s);
    while(s[i] == ' ') {
        //skip spaces
        i++;
        if(i == len) break;

    }
    if(i == len) {
        *index = i;
        return x;
    }

    x = 0;
    bool sign = false;
    if(s[i] == '-') {
        sign = true;
        i++;
    }
    while(s[i] != ' ' && s[i] != '\n' && s[i] != '\0')
        if(s[i] >= '0' && s[i] <= '9') x = x*10 + (s[i++]&0xf);
    if(sign) x = 0 - x;
    *index = i;
    return x;
}

int main() {
    int n, m;
    char s[1024];
    int len;

    //Generate Pascal's triangle
    PascalsTriangle(100);


    while(fgets(s, MAX, stdin)) {
        len = strlen(s);
        int i = 0;
        n = GetNumber(s, &i);
        m = GetNumber(s, &i);

        if(n == 0) break;

        printf("%d things taken %d at a time is %lld exactly.\n", n, m, pt[n][m]);
    }
    return 0;
}
