/* UVa 465 - Overflow http://uva.onlinejudge.org/external/4/465.pdf */
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

static const char FNTB[] = "first number too big";
static const char SNTB[] = "second number too big";
static const char RTB[] = "result too big";
static const unsigned int HIGHEST = 2147483647;

//static inline int GetNumber(string &s) {
static inline int GetNumber(char s[]) {
    //Returns number if not too big, else returns -1
    long long int n = 0;
    int leading = 0;

    while(s[leading] == ' ')
        leading++;

    //if(s.size() > 10) return -1;
    //if(s.strlen() > 10) return -1;

    //Valid integer?
    //for(int i = 0; i < s.size(); ++i) {
    for(int i = leading; i < strlen(s) && s[i] != ' '; ++i) {
        n = n*10 + (s[i]&0xf);
        if(n > HIGHEST) return -1;
    }

    if(n > HIGHEST) return -1;
    return n;
}

int main() {
    int fn, sn;
    //string fns, sns;
    char fns[10000], sns[10000];
    //char op;
    char op[2];
    bool fntb, sntb, rtb;

    //while(cin >> fns >> op >> sns) {
    while(scanf("%s %s %s", &fns, &op, &sns) == 3) {
        fntb = sntb = rtb = false;

        fn = GetNumber(fns);
        if(fn < 0) fntb = rtb = true;

        sn = GetNumber(sns);
        if(sn < 0) sntb = rtb = true;
        //cout << endl<< endl << "IS THIS RIGHT? " << fn << " " << sn << endl<< endl;

        //if (op == '+') {
        if (op[0] == '+') {
            if(!fntb && !sntb)
                if((HIGHEST - fn) < sn) rtb = true;
        }
        else {
            if(fn == 0 || sn == 0) rtb = false;
            else if(!fntb && !sntb)
                if((fn > 0) && ((HIGHEST / fn) < sn)) rtb = true;
        }

        cout << fns << " " << op << " " << sns << endl;
        if(fntb) cout << FNTB << endl;
        if(sntb) cout << SNTB << endl;
        if(rtb) cout << RTB << endl;
    }

    return 0;
}
