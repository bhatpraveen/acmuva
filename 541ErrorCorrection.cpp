/* UVa 541 Error Correction */
//#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main() {
    int n, r, c, bit;
    bool colxor[101], parity, corrupt, cerror, rerror;
    char dummy;

    //while(cin >> n) {
    while(scanf("%d", &n) == 1) {
        if(n < 1) break;
        r = c = 0;
        corrupt = cerror = false;
        memset(colxor, false, (n+1)*sizeof(bool));

        for (int i = 1; i <= n; ++i) {
            rerror = false;
            for (int j = 1; j <= n; ++j) {
                //cin >> bit;
                scanf("%d", &bit);
                rerror = (!rerror != !bit); //logical XOR
                colxor[j] = (!colxor[j] != !bit); //logical XOR
            }
            scanf("%c", &dummy); //newline
            if(rerror) {
                //cout << "rerror at row: " << i << endl;
                if(r) corrupt = true;
                else r = i;
            }
        }

        for(int j = 1; j <= n; ++j) {
            if(colxor[j]) {
                //cout << "rerror at col: " << j << endl;
                if(c) corrupt = true;
                else c = j;
            }
        }

        if(corrupt) printf("Corrupt\n");
        else if(r) printf("Change bit (%d,%d)\n", r, c);
        else printf("OK\n");
    }

    return 0;
}
