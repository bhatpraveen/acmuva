/* UVa 369 - Combinations http://uva.onlinejudge.org/external/3/369.pdf */
#include <cstdio>
#include <vector>
#include <string.h>
//#include <iostream>
using namespace std;

static const int MAX = 10240; //who knows how many leading spaces will be there

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
    long long int n, m, div, num = 0, den = 1;
    char s[1024];
    int len;

    vector<int> numv;
    vector<int> denv;

    while(fgets(s, MAX, stdin)) {
        len = strlen(s);
        int i = 0;
        n = GetNumber(s, &i);
        m = GetNumber(s, &i);

        if(n == 0) break;

        for(int i = m + 1; i <= n; ++i) numv.push_back(i);
        for(int i = 2; i <= n-m; ++i) denv.push_back(i);

        //cout << "num: "; for(int i = 0; i < numv.size(); ++i) cout << numv[i] << " x "; cout << endl;
        //cout << "den: "; for(int j = 0; j < denv.size(); ++j) cout << denv[j] << " x "; cout << endl;

        int ns = numv.size();
        for(int i = 0; i < ns; ++i) {
            int ds = denv.size();
            for(int j = 0; j < ds && denv[j] <= numv[i]; ++j) {
                if(numv[i] % denv[j] == 0) {
                    //printf("%d is divisible by %d, replacing %d by %d and deleting %d\n", numv[i], denv[j], numv[i], numv[i]/ denv[j], denv[j]); //DEBUG
                    numv[i] = numv[i] / denv[j];
                    /* TBD crashing
                    if(numv[i] == 1) {
                        numv.erase(numv.begin() + i);
                        ns = numv.size();
                    }
                    */
                    //denv[j] = 1;
                    denv.erase(denv.begin() + j);
                    ds = denv.size();
                }
            }
        }

        //cout << "num: "; for(int i = 0; i < numv.size(); ++i) cout << numv[i] << " x "; cout << endl;
        //cout << "den: "; for(int j = 0; j < denv.size(); ++j) cout << denv[j] << " x "; cout << endl<< endl<< endl;

        num = den = 1;
        for(int i = 0; i < numv.size(); ++i) num *= numv[i];
        for(int j = 0; j < denv.size(); ++j) den *= denv[j];
        div = 0;
        //cout << num << " " << den << endl;
        if(num > 0 && den > 0 && den <= num) div = num/den;
        printf("%lld things taken %lld at a time is %lld exactly.\n", n, m, div);

        numv.clear();
        denv.clear();
    }
    return 0;
}
