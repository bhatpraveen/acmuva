/* UVa 498 - Polly the Polynomial http://uva.onlinejudge.org/external/4/498.pdf */
#include <cstdio>
#include <string.h>
//#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static const int MAX = 10240;
static char s[MAX]; //who knows what the bloody size is!

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
    int n, len, m;
    long long int c, x;
    long long int poly;
    vector<long long int> cn = vector<long long int>();

    while(fgets(s, MAX, stdin)) { //c0 to cn
        len = strlen(s);
        for(int i = 0; i < len; ++i) {
            c = GetNumber(s, &i);
            //printf("Pushing back %d\n", c);
            cn.push_back(c);
        }

        n = cn.size();
        //nForX = n;
        m = 0;

        //printf("Scanning x now\n");

        fgets(s, MAX, stdin); //x0 to xm
        len = strlen(s);
        for(int i = 0; i < len; ++i) {
            x = GetNumber(s, &i);
            //printf("x= %d\n", x);
            m++;
            //nForX = n - 1;
            poly = cn[0];

            for(int i = 1; i < n; ++i) {
                /*
                Pow function uses double and therefore cause precision errors
                Using Horner's rule instead:
                c_nx^n+c_(n-1)x^(n-1)+...+c_0=((c_nx+c_(n-1))x+...)x+c_0
                */
                //poly += cn[i] * (int)(pow(x, nForX));
                //nForX--;
                poly = (cn[i] + x * poly);
            }
            //poly += cn[n-1];

            if(m > 1) printf(" ");
            printf("%ld", poly);

        }
        printf("\n");
        cn.clear();
    }

    return 0;
}
